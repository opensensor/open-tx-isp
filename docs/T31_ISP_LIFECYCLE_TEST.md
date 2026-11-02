# T31 ISP: Lebenszyklus-Tests auf dem Gerät

Diese Anleitung ist für eine lokale Claude-Sitzung gedacht, die per SSH eine
T31-Kamera mit thingino erreicht. Sie prüft den Branch
`claude/t31-isp-lifecycle2` auf echter Hardware:

| Commit (Titel) | Was auf dem Gerät sichtbar wird |
|---|---|
| clear the MSCA address FIFO and keep buffers on dropped frames | Stream läuft nach Tag/Nacht-Wechsel weiter; `kill -9` stoppt den MSCA-Kanal |
| write the MSCA Y/UV address pair under a per-channel spinlock | keine vertauschte Chroma zwischen Frames (nur indirekt prüfbar) |
| serialise frame-channel ioctls with the per-channel mutex | kein Hänger, kein `blocked for more than 120 seconds` |
| reject QBUF of a buffer the driver still owns | `qbuf: chN buffer N already in use` darf mit OpenIMP nie kommen |
| do not reset a frame channel that another fd is using | zweites `open()` während des Streams stört nicht |
| report a tisp_channel_stop timeout to STREAMOFF and release | Marker `MSCA channel still busy after 3 s` (soll fehlen) |
| stop a running MSCA channel on STREAMOFF in ISP bypass mode | nur mit ISP-Bypass relevant, hier nicht getestet |
| do not start the stream from the 0x400456bf frame wait | mit OpenIMP ohne sichtbare Wirkung |
| drop the raw +0x74 store into struct isp_channel | kein sichtbarer Effekt; darf nichts verschlechtern |
| keep DelSensor from freeing MDNS/WDR buffers under a running ISP | Marker `Sensor release: ISP core quiet after N ms` beim sauberen Stopp |
| free the statistics DMA pages in tisp_deinit | auf dem Gerät nicht erreichbar (siehe Grenzen) |

## Regeln

- **Nichts flashen.** Kein `sysupgrade`, kein Schreiben auf mtd.
- **Nichts unter `/etc` schreiben**, auch nicht indirekt. `POST /control`
  schreibt geänderte Werte nach `<app-config>` zurück. Deshalb läuft the application in
  diesen Tests mit einer Kopie der Konfiguration in `/tmp` (Abschnitt 3).
  `/etc/modules.d/*` wird nur gelesen.
- Auf der Kamera nur nach `/tmp` schreiben.
- **Bilder nur mit Zustimmung des Menschen.** Keine Snapshots und keine
  Streamdaten speichern, ansehen oder auf den PC holen, solange der Mensch das
  nicht ausdrücklich erlaubt hat. Geprüft wird über Bytezähler, JPEG-Header-Bytes
  und dmesg. Ein Snapshot wird sofort nach der Header-Prüfung gelöscht.
- **Nie `0x13309974`, `0x13309a74` oder `0x13309b74` lesen.** Diese Register
  entnehmen beim Lesen einen Eintrag aus dem Done-FIFO. `devmem` nur auf die
  unten genannten Register anwenden.
- Bei Oops, Hänger oder unklarem Zustand: dmesg sichern
  (`dmesg > /tmp/fail.dmesg`, dann per `ssh … cat` auf den PC holen) und die
  Kamera neu starten. Ein Neustart lädt wieder die geflashten Module.
- `rmmod`/`insmod` von `tx_isp_t31` verliert pro Zyklus etwa 160 KiB Kernel-
  Speicher (Statistik-Seiten und WDR-LUT werden beim Entladen nicht
  freigegeben, schon vor diesem Branch). Höchstens zwei, drei Ladezyklen, dann
  neu starten.

## 0. Modul bauen (PC)

```sh
cd open-tx-isp            # Checkout mit Branch claude/t31-isp-lifecycle2
git log --oneline -12     # die Commits oben müssen enthalten sein
TH=~/thingino-firmware ROOT=~/thingino-firmware/output/<t31-kamera> ./build_local.sh
ls -l driver/t31/tx-isp-t31.ko
```

`ROOT` muss die thingino-Ausgabe genau dieser Kamera sein (gleicher Kernel,
gleiche Modulversion), sonst lädt das Modul nicht. Übertragen ohne sftp:

```sh
CAM=192.0.2.x
ssh root@$CAM 'cat > /tmp/tx-isp-t31.ko' < driver/t31/tx-isp-t31.ko
ssh root@$CAM 'md5sum /tmp/tx-isp-t31.ko'; md5sum driver/t31/tx-isp-t31.ko
```

## 1. Bestandsaufnahme (Kamera)

```sh
uname -r; lsmod
cat /etc/modules.d/20-isp /etc/modules.d/30-sensor* 2>/dev/null
M=$(find /lib/modules -name 'tx-isp-t31.ko' | head -1); echo $M
grep -c "new subdevice management system" $M   # >0: geflasht ist open-tx-isp
md5sum <app-config> /etc/modules.d/* > /tmp/etc.md5
grep -E "MemFree|Slab" /proc/meminfo > /tmp/mem.before
which curl wget devmem
```

Voraussetzung: Die Kamera läuft schon mit open-tx-isp und dem OpenIMP-based application
(`/usr/bin/appd`). Ist `grep -c` 0, läuft der Hersteller-Treiber. Dann
abbrechen und dem Menschen melden.

## 2. Streamer stoppen, Testmodul laden (Kamera)

```sh
/etc/init.d/<app-init> stop; sleep 2; pidof appd && echo "appd läuft noch"
lsmod                                 # "Used by" von tx_isp_t31 prüfen
set -- $(cat /etc/modules.d/30-sensor*); SENSOR_MOD=$1
rmmod $SENSOR_MOD
rmmod tx_isp_t31
set -- $(cat /etc/modules.d/20-isp); shift
insmod /tmp/tx-isp-t31.ko "$@" isp_day_night_switch_drop_frame_num=6
set -- $(cat /etc/modules.d/30-sensor*); modprobe "$@"
cat /sys/module/tx_isp_t31/parameters/isp_day_night_switch_drop_frame_num   # 6
dmesg | tail -30
```

`isp_day_night_switch_drop_frame_num=6` wird nur beim `insmod` gesetzt, nicht in
`/etc`. Der Wert erzwingt den Pfad, der vor dem Fix den Stream nach einem
Tag/Nacht-Wechsel eingefroren hat. Lässt sich ein Modul nicht entladen
(`in use`, Hänger), neu starten und das Ergebnis melden.

## 3. The application mit Konfigurationskopie starten (Kamera)

```sh
cp <app-config> /tmp/app-test.conf
start_app() { appd -c /tmp/app-test.conf >/tmp/app.log 2>&1 & sleep 8; }
stop_app()  { kill -TERM $(pidof appd) 2>/dev/null
                for i in 1 2 3 4 5 6 7 8 9 10; do pidof appd >/dev/null || return 0; sleep 1; done
                echo "appd beendet sich nicht"; return 1; }
bytes() { curl -s -m ${1:-5} -o /dev/null -w '%{size_download}\n' http://127.0.0.1:8880/stream.mp4; }
post()  { curl -s -X POST http://127.0.0.1:8880/control -d "$1"; echo; }
start_app; bytes 5          # deutlich > 100000 erwartet
```

Anfragen von `127.0.0.1` brauchen kein Token. Fehlt `curl`, geht
`timeout 5 wget -q -O - http://127.0.0.1:8880/stream.mp4 | wc -c`. Startet
`appd` so nicht, `/etc/init.d/<app-init>` lesen (nicht ändern) und die fehlenden
Vorbereitungen von Hand in `/tmp` nachbauen.

dmesg-Prüfung nach jedem Test:

```sh
FAIL='BUG:|Oops|Unable to handle|scheduling while atomic|sleeping function called|blocked for more than|still busy after 3 s|TIMEOUT waiting for channel|already in use|streaming active|streamoff sensor firstly|the sensor is active|still raising interrupts'
INFO='has no ACTIVE QBUF slot|Stopping streaming on release|already open|ISP core quiet after|stopped channel'
check() { dmesg > /tmp/$1.dmesg; echo "== $1"; grep -E "$FAIL" /tmp/$1.dmesg | head; grep -cE "$INFO" /tmp/$1.dmesg; grep -E "$INFO" /tmp/$1.dmesg | sort | uniq -c | sort -rn | head; dmesg -c >/dev/null; }
dmesg -c >/dev/null
```

`dmesg -c` leert nur den Kernel-Puffer. Vor jedem Leeren ist der Inhalt in
`/tmp/<test>.dmesg` gesichert.

## 4. Tests

Register (32 Bit, nur lesen): `devmem 0x13309804 32` zeigt in Bit n, ob
MSCA-Kanal n läuft (die Bits 16..19 sind meist gesetzt und hier ohne Belang). `devmem 0x13309808 32`
zeigt in Bit n, ob Kanal n noch arbeitet.

### T1: Start/Stopp-Schleife (20 Runden)

```sh
stop_app
for r in $(seq 20); do
  start_app; b=$(bytes 5); stop_app
  echo "runde $r bytes=$b 9804=$(devmem 0x13309804 32) 9808=$(devmem 0x13309808 32)"
done
check T1
```

Erwartung: jede Runde deutlich mehr als 100000 Bytes. Nach dem Stopp sind in
`0x13309804` die Bits 0..2 null. In `T1.dmesg` stehen keine FAIL-Treffer. Beendet
The application die Sitzung sauber (DisableSensor, DelSensor), steht pro Runde einmal
`Sensor release: ISP core quiet after N ms` (N ist typisch zwei
Frame-Perioden, etwa 80 bei 25 fps). Fehlt der Marker,
ruft the application DelSensor nicht auf. Das ist kein Fehler, aber im Bericht notieren.
Einzelne `has no ACTIVE QBUF slot` direkt nach einem Start sind Altlasten aus
dem Done-FIFO. Viele davon oder welche mitten im Lauf sind ein Befund.

### T2: Tag/Nacht-Schleife (20 Wechsel, Stream läuft)

```sh
start_app
curl -s -m 260 -o /dev/null -w 'dauer-client %{size_download}\n' http://127.0.0.1:8880/stream.mp4 > /tmp/t2.client &
for r in $(seq 10); do
  post '{"image":{"running_mode":1}}'; sleep 5; echo "nacht $r $(bytes 3)"
  post '{"image":{"running_mode":0}}'; sleep 5; echo "tag   $r $(bytes 3)"
done
wait; cat /tmp/t2.client
check T2
```

Erwartung: Jeder kurze Abruf liefert Daten (grob die Bitrate mal 3 s). Der
Dauer-Client bricht nicht ab und liefert über die ganze Laufzeit Daten. Vor dem
Fix fror der Stream mit `drop_frame_num=6` beim ersten Wechsel ohne
dmesg-Meldung ein. Zum Schluss `running_mode` auf den Wert aus
`/tmp/app-test.conf` zurücksetzen. Das Bild bei Nacht nicht beurteilen, ohne
Zustimmung werden keine Bilder angesehen.

### T3: `kill -9` des Streamers (10 Runden)

```sh
for r in $(seq 10); do
  pidof appd >/dev/null || start_app
  curl -s -m 20 -o /dev/null http://127.0.0.1:8880/stream.mp4 & sleep 5
  kill -9 $(pidof appd); sleep 1
  echo "runde $r 9804=$(devmem 0x13309804 32)"
  wait; start_app; echo "neu $r $(bytes 5)"
done
stop_app; check T3
```

Erwartung: Nach `kill -9` sind die Bits 0..2 von `0x13309804` null, in dmesg
stehen `Stopping streaming on release` und `stopped channel`. Der neu gestartete
The application liefert jedes Mal Daten. Bekannte Grenze: Nach `kill -9` laufen Sensor,
VIC und MDNS weiter, weil kein DisableSensor kommt. Das ist nicht Gegenstand
dieses Tests.

### T4: Snapshot parallel zum Stream (30 Abrufe)

```sh
start_app
curl -s -m 120 -o /dev/null -w 'client %{size_download}\n' http://127.0.0.1:8880/stream.mp4 > /tmp/t4.client &
for r in $(seq 30); do
  curl -s -m 5 -o /tmp/s.jpg http://127.0.0.1:8880/snapshot.jpg
  echo "snap $r size=$(wc -c </tmp/s.jpg) head=$(od -An -tx1 -N2 /tmp/s.jpg)"
  rm -f /tmp/s.jpg; sleep 2
done
wait; cat /tmp/t4.client
check T4
```

Erwartung: Jede Antwort beginnt mit `ff d8` und ist einige KiB groß. Der
Stream-Client läuft durch. Die JPEGs werden nicht geöffnet und nicht kopiert.

### T5: Zweites `open()` eines laufenden Frame-Kanals

```sh
curl -s -m 30 -o /dev/null -w 'client %{size_download}\n' http://127.0.0.1:8880/stream.mp4 > /tmp/t5.client &
sleep 5
for r in 1 2 3 4 5; do exec 3</dev/framechan0; sleep 1; exec 3<&-; sleep 2; done
wait; cat /tmp/t5.client
check T5
```

Erwartung: dmesg zeigt je Runde `Frame channel 0 already open (1), keeping its
state (streaming=1)`. Beim Schließen darf **kein** `Stopping streaming on
release` erscheinen. Der Client läuft ohne Pause durch. Vor dem Fix hat das
zweite `open()` die Slot-Tabelle des laufenden Streams gelöscht.

### T6: Leerlauf-Kick (Tag/Nacht ohne Client)

The application schaltet chn0 bei einem `running_mode`-POST ohne Client für ~500 ms ein
und wieder aus (EnableChn/DisableChn). Das ist ein häufiger Zyklus:

```sh
sleep 20      # chn0 muss im Leerlauf aus sein: "disabled (idle)" in /tmp/app.log oder logread
for r in $(seq 20); do post '{"image":{"running_mode":1}}'; sleep 3; post '{"image":{"running_mode":0}}'; sleep 3; done
echo "danach $(bytes 5)"
check T6
```

Erwartung: keine FAIL-Treffer, danach liefert der Stream sofort Daten.

### T7: Speicher

```sh
stop_app
grep -E "MemFree|Slab" /proc/meminfo; cat /tmp/mem.before
```

Erwartung: Kein stetiges Wachstum von `Slab` über die Tests hinweg. Der
einmalige Unterschied durch das Laden des Testmoduls ist normal.

## 5. Aufräumen

```sh
stop_app
md5sum -c /tmp/etc.md5          # alles "OK", /etc ist unverändert
reboot                          # lädt die geflashten Module, startet <app-init>
```

Nach dem Neustart `pidof appd` und `bytes 5` prüfen.

## 6. Bericht an den Menschen

- Kamera, Sensor, `uname -r`, Commit-Stand des Moduls.
- Für T1 bis T7 jeweils bestanden oder nicht bestanden, mit Bytezahlen und
  `devmem`-Werten.
- Alle FAIL-Treffer im Wortlaut, dazu die INFO-Zählung je Test.
- Ob `Sensor release: ISP core quiet after N ms` erschien und welche N-Werte.
- Auffälligkeiten beim Laden oder Entladen des Moduls.
- Keine Bilder anhängen, es sei denn, der Mensch hat zugestimmt.

## Anhang: dmesg-Marker

| Marker | Bedeutung | Erwartet |
|---|---|---|
| `qbuf: chN buffer N already in use (state S)` | QBUF eines Puffers, den der Treiber noch hält | nie (OpenIMP) |
| `reqbufs: channel N streaming active` | REQBUFS während eines laufenden Streams, jetzt `-EBUSY` | nie |
| `Frame channel N already open (K), keeping its state` | weiteres `open()`, der Zustand bleibt erhalten | nur in T5 |
| `Channel N: STREAMOFF: MSCA channel still busy after 3 s` | `tisp_channel_stop` lief in den Timeout | nie |
| `Channel N: release: MSCA channel still busy after 3 s` | dasselbe beim Schließen (Absturz, `kill -9`) | nie |
| `tisp_channel_stop: TIMEOUT waiting for channel N` | Detailzeile zum Timeout | nie |
| `ispcore_frame_channel_streamoff: stopped channel N (0)` | MSCA-Kanal gestoppt, Ergebnis 0 | bei jedem Stopp |
| `Stopping streaming on release` | Kanal ohne STREAMOFF geschlossen | nur T3 |
| `Please, streamoff sensor firstly!` | DelSensor bei laufendem Sensor abgewiesen | nie |
| `the sensor is active, please stop it firstly.` | Sensor-Freigabe bei laufendem Sensor abgewiesen | nie |
| `Sensor release: ISP core quiet after N ms` | DelSensor: ISP ohne Interrupt, Puffer frei gegeben | bei sauberem Stopp |
| `Sensor release: ISP core still raising interrupts after 1 s` | ISP meldet trotz gestopptem Sensor weiter Interrupts | nie; sonst Befund |
| `MSCA chN completion 0x… has no ACTIVE QBUF slot` | Done-Eintrag ohne passenden Slot | höchstens vereinzelt nach Start |
| `blocked for more than 120 seconds` | Hänger, z. B. Deadlock am Frame-Kanal-Mutex | nie |
| `scheduling while atomic` / `sleeping function called from invalid context` | Schlafen unter Spinlock | nie |

## Grenzen dieser Tests

- `tisp_deinit` (Freigabe der Statistik-Seiten) läuft nur über
  `ispcore_slake_module`, das heute keinen Aufrufer hat. Das ist auf dem Gerät
  nicht prüfbar.
- Ob das MDNS/WDR-DMA nach DelSensor wirklich ruht, zeigt nur ein Poison-Test in
  OpenIMP: `DMA_FreePhys` füllt den Block mit `0xA5`, hält ihn einen Zyklus
  zurück und prüft das Muster vor der Wiedervergabe. Dafür braucht es einen
  eigenen OpenIMP-Build, er gehört nicht zu diesen Tests.
- Die Y/UV-Atomarität zeigt sich nur als seltene Farbvertauschung zwischen zwei
  Frames. Ohne Bildprüfung ist sie hier nicht nachweisbar.
- Der Bypass-Pfad (`ISP_CTRL_BYPASS`) wird von the application nicht benutzt.

## Latenz-Messung (Branch `claude/t31-isp-latency`)

Dieser Abschnitt misst, ob der Latenz-Branch die langen Phasen mit
abgeschalteten Interrupts beseitigt. Er baut auf den Abschnitten 0 bis 3 auf
(Regeln, Modul laden, `start_app`, `stop_app`, `bytes`, `post`, `check`).
Verglichen werden zwei Module mit gleicher Kamera, Szene und Konfiguration:

- **alt**: Stand `claude/t31-isp-all` (Commit `999a62b`)
- **neu**: Stand `claude/t31-isp-latency`

| Commit (Titel) | Was sich messen lässt |
|---|---|
| do not zero the active parameter block before overwriting it | kürzerer Tag/Nacht-Wechsel |
| refresh each day/night module with local IRQs off | kein eigener Messwert |
| run the day/night parameter switch from a work item | keine ms-Spitze pro Tag/Nacht-Wechsel (L2, L3) |
| serialize the day/night and custom bank switches | kein Hänger (`blocked for more than`) |
| cancel the day/night work on module exit before tisp_deinit_free | kein Oops beim `rmmod` (L1) |
| stop logging every poll of the VIC error-recovery loop | nur bei VIC-Fehlern: keine `addr ctl is`-Flut |
| bound the release-ack poll of the WDR exception reset | nur im WDR-Modus bei Fehlern, sonst nicht erreichbar |
| rate-limit the VIC interrupt error lines | nur bei VIC-Fehlern: höchstens 20 `Err [VIC_INT]` pro 5 s |
| let the AE0 solver read the unpacked statistics planes directly | wenige µs pro Frame, nicht einzeln messbar |
| clear only the unused tail of the AE0 statistics planes | wenige µs pro Frame, nicht einzeln messbar |
| skip the AE1 statistics work in linear mode | `ctxt`/s in `/proc/stat` sinkt um etwa die Bildrate (L4) |

### L0: Module und Messprogramm bauen (PC)

Beide Module wie in Abschnitt 0 bauen und als `/tmp/tx-isp-alt.ko` und
`/tmp/tx-isp-neu.ko` auf die Kamera kopieren. Dazu ein kleines Messprogramm im
Stil von `cyclictest`: Es schläft in einer Schleife 1 ms mit SCHED_FIFO und
misst, wie spät es aufwacht. Jede Phase mit abgeschalteten Interrupts verzögert
den Timer-Interrupt und damit das Aufwachen um genau diese Zeit.

```sh
cat > /tmp/latprobe.c <<'EOF'
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sched.h>
#include <sys/mman.h>

int main(int argc, char **argv)
{
	int secs = argc > 1 ? atoi(argv[1]) : 60, s = 0;
	struct sched_param sp = { .sched_priority = 90 };
	struct timespec next, now;
	long lat, max = 0, smax = 0, n = 0, b[4] = { 0 };

	if (sched_setscheduler(0, SCHED_FIFO, &sp))
		perror("sched_setscheduler");
	mlockall(MCL_CURRENT | MCL_FUTURE);
	clock_gettime(CLOCK_MONOTONIC, &next);
	while (s < secs) {
		next.tv_nsec += 1000000;
		if (next.tv_nsec >= 1000000000) {
			next.tv_nsec -= 1000000000;
			next.tv_sec++;
		}
		clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &next, NULL);
		clock_gettime(CLOCK_MONOTONIC, &now);
		lat = (now.tv_sec - next.tv_sec) * 1000000L +
		      (now.tv_nsec - next.tv_nsec) / 1000;
		if (lat > max)
			max = lat;
		if (lat > smax)
			smax = lat;
		b[lat >= 2000 ? 3 : lat >= 1000 ? 2 : lat >= 500 ? 1 : 0]++;
		next = now; /* eine Spitze nur einmal zählen */
		if (++n % 1000 == 0) {
			printf("t=%d max_us=%ld\n", ++s, smax);
			fflush(stdout);
			smax = 0;
		}
	}
	printf("gesamt n=%ld max_us=%ld <500:%ld 500-999:%ld 1000-1999:%ld >=2000:%ld\n",
	       n, max, b[0], b[1], b[2], b[3]);
	return 0;
}
EOF
$ROOT/host/bin/mipsel-linux-gcc -static -O2 -Wall -o /tmp/latprobe /tmp/latprobe.c
ssh root@$CAM 'cat > /tmp/latprobe && chmod +x /tmp/latprobe' < /tmp/latprobe
```

Der Kernel der Kamera hat `CONFIG_HIGH_RES_TIMERS=y`, 1 ms Periode geht also.
Die Zeile `t=N max_us=M` ist etwa eine pro Sekunde. Sie zeigt die größte
Verspätung dieser Sekunde.

### L1: Modul wechseln (Kamera)

Wie Abschnitt 2, aber mit dem jeweiligen Modul und **ohne**
`isp_day_night_switch_drop_frame_num` (Standard 0), damit nur die Latenz
gemessen wird:

```sh
KO=/tmp/tx-isp-alt.ko      # zweiter Durchlauf: /tmp/tx-isp-neu.ko
/etc/init.d/<app-init> stop; sleep 2
set -- $(cat /etc/modules.d/30-sensor*); rmmod $1; rmmod tx_isp_t31
set -- $(cat /etc/modules.d/20-isp); shift; insmod $KO "$@"
set -- $(cat /etc/modules.d/30-sensor*); modprobe "$@"
dmesg -c >/dev/null; start_app; bytes 5
```

Höchstens zwei, drei Modulwechsel pro Neustart (Speicherverlust beim Entladen,
siehe Regeln). Sicherer ist: alt messen, neu starten, neu messen.

### L2: Grundlast und Tag/Nacht-Schleife mit Latenz-Sonde

```sh
# 60 s Grundlast: Stream läuft, keine Wechsel
curl -s -m 70 -o /dev/null http://127.0.0.1:8880/stream.mp4 &
/tmp/latprobe 60 > /tmp/lat-ruhe.txt; wait
tail -1 /tmp/lat-ruhe.txt

# 120 s mit Tag/Nacht-Wechsel alle 5 s
curl -s -m 130 -o /dev/null http://127.0.0.1:8880/stream.mp4 &
/tmp/latprobe 120 > /tmp/lat-dn.txt &
for r in $(seq 12); do
  post '{"image":{"running_mode":1}}'; sleep 5
  post '{"image":{"running_mode":0}}'; sleep 5
done
wait
tail -1 /tmp/lat-dn.txt
sort -t= -k3 -n /tmp/lat-dn.txt | tail -5      # die fünf größten Sekunden
check L2
```

Auswertung: Die Zahl der Sekunden mit `max_us` über 1000 in `lat-dn.txt` mit der
Zahl der Wechsel (24) vergleichen, jeweils für alt und neu. Erwartung: Mit
**alt** hat fast jede Sekunde mit einem Wechsel eine Spitze in der
Größenordnung 1 bis 5 ms. Mit **neu** liegen die Spitzen während der Wechsel
nahe an der Grundlast aus `lat-ruhe.txt`, höchstens einige 100 µs darüber
(längstes einzelnes Modul). Die Grundlast selbst ändert sich kaum, denn die
AE/AWB-Algorithmen laufen weiterhin mit abgeschalteten Interrupts.

In `L2.dmesg` pro Wechsel eine Zeile `Day/night mode updated: 0` bzw. `: 1`
(etwa 24). FAIL-Treffer sind zusätzlich zu Abschnitt 3:
`T31 day/night switch failed`, `T31 day/night apply failed`.

Danach `running_mode` auf den Wert aus `/tmp/app-test.conf` zurücksetzen.

### L3: Frame-Abstände (nur mit Zustimmung)

Die Frame-Zeitstempel entstehen im ISP-Interrupt. Beim alten Modul lief der
Tag/Nacht-Wechsel im selben Interrupt **vor** der Frame-Abholung, der
Zeitstempel des Frames wurde also um die Dauer des Wechsels verschoben. Das
zeigt sich als Ausreißer im Frame-Abstand. Die Messung holt Stream-Daten auf den
PC. Deshalb nur, wenn der Mensch zugestimmt hat. Es werden nur Zeitstempel
ausgegeben, keine Bilder gespeichert.

```sh
# PC, während auf der Kamera die Schleife aus L2 läuft (ohne latprobe)
ffprobe -v error -rtsp_transport tcp -select_streams v:0 \
  -show_entries packet=pts_time -of csv=p=0 -read_intervals '%+120' \
  "rtsp://<user>:<pass>@$CAM:554/ch0" > /tmp/pts.txt
awk 'NR>1 { d = ($1 - p) * 1000; if (d > m) m = d; s += d; n++;
            if (d > 1.5 * 1000 / 25) big++ } { p = $1 }
     END { printf "n=%d mittel=%.2f ms max=%.2f ms lange=%d\n", n, s/n, m, big }' /tmp/pts.txt
```

Pfad (`video0.rtsp_path`) und Zugangsdaten aus der Anwendungskonfiguration nehmen. `25` durch die
Bildrate von `video0.fps` ersetzen. Erwartung: Bei alt ist die Streuung um die
Wechsel sichtbar größer als bei neu. Mittelwert und Frame-Zahl bleiben gleich.

### L4: Interrupts und Kontextwechsel (linearer Modus)

```sh
snap() { grep -E 'isp-m0|isp-w02' /proc/interrupts; grep -E '^ctxt' /proc/stat; }
curl -s -m 70 -o /dev/null http://127.0.0.1:8880/stream.mp4 &
sleep 5; snap > /tmp/s0; sleep 60; snap > /tmp/s1; wait
paste /tmp/s0 /tmp/s1
```

Differenzen durch 60 teilen. Erwartung: Die Interrupt-Raten von `isp-m0` (37)
und `isp-w02` (38) sind bei alt und neu gleich. `ctxt`/s ist bei neu etwa um die
Bildrate kleiner (AE1-Ereignis entfällt ohne WDR). Läuft die Kamera im
WDR-Modus, bleibt `ctxt`/s gleich.

### L5: Drop-Frames nach dem Wechsel

T2 aus Abschnitt 4 mit dem neuen Modul und
`isp_day_night_switch_drop_frame_num=6` wiederholen. Erwartung wie dort: Der
Stream läuft nach jedem Wechsel weiter. Neu gilt der Zählwert ab dem Moment, in
dem die neuen Parameter aktiv sind. Pro Wechsel fehlen also mindestens 6 Frames,
gelegentlich einer mehr.

### L6: Fehlerpfade (nur beobachten)

VIC-Fehler und die WDR-Ausnahme lassen sich nicht gezielt auslösen. Treten sie
auf, gilt:

| Marker | Bedeutung | Erwartet |
|---|---|---|
| `Err [VIC_INT] : …` | VIC-Fehlerbit | höchstens 20 Zeilen pro 5 s, danach `… callbacks suppressed` |
| `VIC error handler: status 0x…, restarting VIC` | VIC-Neustart nach Fehler | vereinzelt; `addr ctl is` gibt es nicht mehr pro Schleifendurchlauf |
| `VIC error handler: VIC did not stop, addr ctl is 0x…` | VIC blieb 1 ms lang aktiv, Neustart trotzdem | nie; sonst Befund |
| `ispcore: WDR exception reset: no release ack` | ISP bestätigte die Freigabe 1 ms lang nicht | nie; sonst Befund (vorher: Hänger) |
| `scheduling while atomic` / `sleeping function called from invalid context` | u. a. WDR-Refresh im Interrupt (alt) | nie mit neu |

Im Bericht zu L2 bis L5 die Zahlen für alt und neu nebeneinander angeben
(`gesamt`-Zeile von `latprobe`, Anzahl der Sekunden über 1 ms, `ctxt`/s,
Interrupt-Raten, bei Zustimmung die `ffprobe`-Zeile).
