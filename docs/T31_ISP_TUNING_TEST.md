# T31 ISP-Tuning: Testanleitung für den Branch `claude/t31-isp-tuning`

Diese Anleitung richtet sich an eine lokale Claude-Session mit SSH-Zugang zu
einer T31-Kamera mit thingino und open-tx-isp. Sie prüft die Korrekturen der
Tuning-Steuerungen (Bug-IDs B2–B17 aus der Lückenanalyse) ohne Flashen und
möglichst ohne Bildvergleich.

## 0. Regeln

- **Niemals flashen**: kein `sysupgrade`, kein `flashcp`, kein `fw_setenv`.
- **Nichts nach `/etc`, `/opt` oder in ein anderes persistentes Verzeichnis
  schreiben.** Alles, was auf die Kamera kommt, liegt in `/tmp` (tmpfs).
  `/etc/modules.d/*` nur lesen.
- Das installierte Modul im Flash bleibt unverändert. Ein `reboot` oder
  Stromzyklus stellt den Ausgangszustand vollständig wieder her.
- **Bilder, Snapshots oder Streams nur mit ausdrücklicher Zustimmung der
  Person aufnehmen.** Alle Tests unten kommen mit Registern, ioctl-Rückgaben
  und `dmesg` aus. Manche Tests verändern das Livebild kurz (vermerkt); das
  ist in Ordnung, solange nichts aufgezeichnet wird.
- Vor dem Modultausch die Person informieren. Hängt die Kamera danach, muss
  sie eventuell von Hand stromlos gemacht werden.

Platzhalter: `CAM` = Hostname/IP der Kamera, `TH` = lokaler Checkout von
`thingino-firmware` mit einem **gebauten** Output für genau dieses
Kameraprofil, `ROOT` = `$TH/output/<profil>`.

## 1. Voraussetzungen prüfen

Auf der Kamera (nur lesen):

```sh
ssh root@CAM 'uname -r; cat /proc/cpuinfo | grep -i "machine\|system type"; lsmod'
ssh root@CAM 'cat /etc/modules.d/20-isp; cat /etc/modules.d/30-sensor* 2>/dev/null'
ssh root@CAM 'ls /etc/init.d/ | grep -Ei "stream|rtsp|video"'
ssh root@CAM 'modinfo tx_isp_t31 2>/dev/null || find /lib/modules -name "tx-isp-t31.ko"'
ssh root@CAM 'cat /proc/jz/isp/isp-m0; which devmem'
```

Weiter nur, wenn:

- der SoC ein T31 ist und `tx_isp_t31` geladen ist,
- die Kamera bereits open-tx-isp verwendet (thingino-Paket `open-tx-isp`;
  `/proc/jz/isp/isp-m0` zeigt die Zeilen `ISP Runing Mode : ...` aus
  thingino-Patch 0005). Mit dem Stock-Blob nicht testen, dort fehlt der
  Vergleichsstand.
- `devmem` vorhanden ist.

Notieren: Streamer-Init-Skript (z. B. `/etc/init.d/S95<app>`), Modulparameter aus `20-isp`, Sensormodul und Parameter aus
`30-sensor*`, `uname -r`.

## 2. Modul bauen (lokal)

Der Branch wird mit denselben thingino-Patches gebaut, die auch das
installierte Modul enthält (0001–0005), sonst fehlen z. B. die
`isp-m0`-Felder.

```sh
cd /pfad/zu/open-tx-isp            # Checkout mit dem Branch
B=/tmp/itx-test; rm -rf $B; mkdir -p $B
git archive claude/t31-isp-tuning | tar -x -C $B
for p in $TH/package/open-tx-isp/*.patch; do (cd $B && patch -p1 < $p) || echo "FEHLER: $p"; done
cd $B && TH=$TH ROOT=$ROOT SOC=t31 ./build_local.sh
ls -l $B/driver/t31/tx-isp-t31.ko
```

Prüfen, dass die Kernelversion passt:

```sh
strings $B/driver/t31/tx-isp-t31.ko | grep '^vermagic='   # muss zu `uname -r` der Kamera passen
```

Testprogramm bauen (statisch, damit die libc der Kamera egal ist):

```sh
$ROOT/host/bin/mipsel-linux-gcc -static -O2 -Wall -o $B/t31_isp_tune_test $B/tools/t31_isp_tune_test.c
```

Übertragen (thingino-dropbear hat oft kein sftp, daher über `cat`):

```sh
ssh root@CAM 'cat > /tmp/tx-isp-t31.ko' < $B/driver/t31/tx-isp-t31.ko
ssh root@CAM 'cat > /tmp/t31_isp_tune_test && chmod +x /tmp/t31_isp_tune_test' < $B/t31_isp_tune_test
```

Im Folgenden `T=/tmp/t31_isp_tune_test` auf der Kamera.

## 3. Ausgangswerte mit dem installierten Modul

Streamer läuft normal. Werte notieren (sie dienen als Vergleich):

```sh
T=/tmp/t31_isp_tune_test
$T expr
$T get 0x98091b; $T get 0x8000086; $T get 0x980918; $T get 0x8000028; $T get 0x80000e0
for a in 0x1330000c 0x13304808 0x13304848 0x13304860 0x1330885c 0x13308860 0x13308864 0x13308868 \
         0x13305004 0x13305008 0x1330500c 0x13305010 0x13305014 0x13340000 0x13340004; do
  echo "$a $(devmem $a 32)"; done
dmesg | tail -20
```

## 4. Modul tauschen (nur `/tmp`, nichts Persistentes)

1. Absicherung für diese Sitzung (flüchtig, gilt nur bis zum Reboot):
   ```sh
   echo 1 > /proc/sys/kernel/panic_on_oops; echo 10 > /proc/sys/kernel/panic
   ```
   Ein Oops im Testmodul führt so zu einem Neustart mit dem Modul aus dem Flash.
2. Streamer stoppen, z. B. `/etc/init.d/<app-init> stop` (bzw. das in Abschnitt 1
   gefundene Skript). Prüfen, dass kein Prozess mehr `/dev/isp-m0`,
   `/dev/tx-isp` oder `/dev/framechan*` offen hat:
   ```sh
   ls -l /proc/[0-9]*/fd 2>/dev/null | grep -E 'isp|framechan|video' || echo frei
   ```
3. Sensor- und ISP-Modul entladen (Namen aus Abschnitt 1):
   ```sh
   rmmod sensor_<modell>_t31 && rmmod tx_isp_t31
   ```
   Schlägt `rmmod` fehl: **nicht erzwingen**, `reboot` und aufhören.
4. Testmodul und Sensor laden, mit denselben Parametern wie in
   `/etc/modules.d/20-isp` bzw. der in Abschnitt 1 notierten Sensorzeile:
   ```sh
   insmod /tmp/tx-isp-t31.ko $(sed 's/^[^ ]* *//' /etc/modules.d/20-isp)
   modprobe <sensorzeile aus 30-sensor*, also Modulname plus Parameter>
   ```
   `modprobe` löst die Abhängigkeit des Sensors gegen das bereits geladene
   `tx_isp_t31` aus `/tmp` auf.
5. Streamer starten, 10–20 s warten, `dmesg | tail -50` auf Oops/Fehler
   prüfen, `cat /proc/jz/isp/isp-m0` muss plausible Werte zeigen. Der Streamer
   muss laufen: AE, Statistik und Registerrefresh arbeiten nur bei laufender
   Pipeline. Das Testprogramm öffnet `/dev/isp-m0` als zweiten Handle; das
   ist mit diesem Treiber unkritisch (das Schließen gibt nur den eigenen
   ioctl-Puffer frei).

**Rückweg jederzeit:** `reboot`.

Für stabile Registervergleiche (Tests 5.8–5.10) AE einfrieren und am Ende
wieder freigeben:

```sh
$T set 0x8000034 1    # AE hält das aktuelle Tupel
...
$T set 0x8000034 0
```

## 5. Tests

Fehlschläge zeigt das Programm als `ioctl ... ret=-1 errno=N (...)`. Nach
jedem Block `dmesg | tail` auf `Oops`, `BUG` oder `Unable to handle` prüfen.

### 5.1 Protokollierung (pr_info → pr_debug)

`dmesg -c >/dev/null; $T set 0x98091b 128; dmesg` – es darf keine Zeile
`Set control: cmd=...` erscheinen (nur „ISP M0 device open/release“ vom
Öffnen des Geräts).

### 5.2 B7/B15: kein Kernel-Stack mehr in den Zonen-Gettern

```sh
$T getptr 0x8000046 900 | sort | uniq -c   # AF-Zonen: nur Nullen
$T getptr 0x8000030 900 | head             # AE-Zonen: echte Werte, kein a5-Muster
$T getptr 0x8000030 900 | md5sum; sleep 2; $T getptr 0x8000030 900 | md5sum   # ändert sich mit der Szene
$T getptr 0x8000045 20                     # 20 Nullbytes, ret 0
```

Erwartet: 0x8000046 und 0x8000045 nur `00`; 0x8000030 enthält weder
zufällige Kernelzeiger (`8xxxxxxx`-Muster) noch `a5 a5 ...`.

### 5.3 B2/B3: SetAe_IT_MAX, GetExpr, SetAeMin

```sh
$T expr                    # it, it_min, it_max, line_us; it_max muss > 0 sein
$T get 0x8000032           # gleich it_max
```

Kappe unter die aktuelle Integrationszeit setzen (Beispiel: `it` = 1200 → 600):

```sh
$T set 0x8000032 600
$T get 0x8000032           # 600
$T expr                    # it_max=600
sleep 3; $T expr           # it <= 600
$T getptr 0x8000026 24     # EV-Attr: again/dgain (log2, 32 = 2x) steigen zum Ausgleich
$T set 0x8000032 0         # muss mit errno 22 (EINVAL) scheitern
$T set 0x8000032 <altes it_max>
```

Ist die Szene so hell, dass `it` schon sehr klein ist, die Kappe auf etwa die
Hälfte des aktuellen `it` setzen; in dunkler Szene ist der Effekt deutlicher.
Hinweis: Wie im Stock setzt ein FPS-Wechsel oder ein Tag/Nacht-Wechsel die
Kappe auf das Sensorlimit zurück. `/proc/jz/isp/isp-m0` zeigt mit Patch 0005
das Sensorlimit (`sensor->attr`), nicht die AE-Kappe; maßgeblich ist `expr`.

Falls die Anwendung `image.ae_it_max_us` bereits konfiguriert
ist: im Anwendungs-Log muss statt „GetExpr gave no line/max reference“ nun
„capped AE at … lines“ und später „cap in effect“ stehen. Die Konfiguration
dafür **nicht** ändern, wenn sie nach `/etc` geschrieben würde.

SetAeMin (16 Byte: it_min, ag_min, it_short_min, ag_short_min):

```sh
$T getptr 0x800002f 16                    # Ausgangswerte merken
$T setptr 0x800002f 4,0x400,0,0
sleep 1; $T getptr 0x800002f 16           # 04 00 00 00 00 04 00 00 ...
$T expr                                   # it_min=4
$T setptr 0x800002f 0,0x400,0,0           # it_min 0 wird abgelehnt (dmesg-Warnung), ret 0
$T setptr 0x800002f <alte Werte>
```

### 5.4 B14: Bereichsprüfung SetMaxAgain

```sh
$T get 0x8000028                 # Wert merken (log2, 32 pro Blendenstufe)
$T set 0x8000028 0xffffffff      # muss scheitern (errno 1, EPERM, wie Stock -1)
$T set 0x8000028 <alter Wert>    # ret 0
```

### 5.5 B12: Anti-Flicker mit negativem Wert

```sh
$T get 0x980918                  # merken (0 aus, 1 = 50 Hz, 2 = 60 Hz)
$T set 0x980918 0xffffffff       # errno 22
$T set 0x980918 3                # errno 22
$T set 0x980918 <alter Wert>
```

### 5.6 Lücke 8: Anti-Flicker nach SetSensorFPS

Ändert kurz die Bildrate des Streams.

```sh
$T get 0x80000e0                 # gepackt: (num << 16) | den, z. B. 0x190001 = 25/1
$T set 0x980918 1                # 50 Hz
dmesg -c > /dev/null
$T set 0x80000e0 0x140001        # 20 fps
dmesg | grep T31_DEFLICK         # neue Zeile direkt nach dem Set, total/last_idx zur neuen Framelänge
$T set 0x80000e0 <alter Wert>; $T set 0x980918 <alter Wert>
```

Vorher (ohne Fix) erschien nach dem FPS-Wechsel keine `T31_DEFLICK`-Zeile.
Ob sich `step` ändert, hängt davon ab, ob der Sensor die Bildrate über die
Zeilenzahl (dann bleibt `step` gleich, `total` ändert sich) oder über den
Pixeltakt regelt.

### 5.7 B9: SetModuleControl über Zeiger

```sh
devmem 0x1330000c 32
$T getptr 0x80000e2 4            # Wort W (little endian); W & 0x7ffff == Register & 0x7ffff,
                                 # Bit 31 gesetzt, wenn MDNS aus ist
$T setptr 0x80000e2 <W>          # dasselbe Wort zurückschreiben
devmem 0x1330000c 32             # unverändert, Bild unverändert
```

Keine anderen Bits setzen – das schaltet ISP-Blöcke ab.

### 5.8 B4: Schärfe idempotent (AE einfrieren, Szene ruhig halten)

```sh
$T set 0x8000034 1
r() { for a in 0x13304808 0x13304848 0x13304860; do printf '%s ' $(devmem $a 32); done; echo; }
$T set 0x98091b 128; r           # Basis A
$T set 0x98091b 200; r           # B
$T set 0x98091b 200; r           # muss gleich B sein (vorher: weiter gestiegen)
$T set 0x98091b 128; r           # muss gleich A sein
$T set 0x98091b 60;  r; $T set 0x98091b 60; r   # zweimal gleich
$T set 0x98091b <alter Wert>
```

### 5.9 B5: Sinter (2D-NR) idempotent und sofort wirksam

```sh
s() { for a in 0x1330885c 0x13308860 0x13308864 0x13308868; do printf '%s ' $(devmem $a 32); done; echo; }
$T set 0x8000086 128; s          # A
$T set 0x8000086 200; s          # B – muss sich SOFORT von A unterscheiden (AE ist eingefroren)
$T set 0x8000086 200; s          # gleich B
$T set 0x8000086 128; s          # gleich A
$T set 0x8000086 <alter Wert>
```

### 5.10 B6: Defog-Stärke idempotent

SetDefog_Strength erwartet einen Zeiger auf **ein Byte**:

```sh
$T get 0x8000039                 # aktueller Wert
$T setb 0x8000039 200; $T get 0x8000039    # 200
$T setb 0x8000039 200; $T setb 0x8000039 128; $T get 0x8000039
```

Die Transmissionslisten liegen nur im Treiber und haben kein eigenes
Register; der Defog-Block-RAM (`0x13358000…`) hängt von der Szene ab. Daher
hier nur Funktionsprüfung (ret 0, Getter stimmt, kein Oops). Eine visuelle
Prüfung (200, 200, 128 muss wie der Ausgangszustand aussehen) nur mit
Zustimmung und nur, wenn Defog aktiv ist (nicht selbst einschalten).

### 5.11 B8/B17: AE-Gewichte, Histogramm, Userpointer

```sh
$T getptr 0x800002d 225 > /tmp/w.txt; cat /tmp/w.txt    # 225 Bytes, alle 00..08
W=$(awk '{for(i=1;i<=NF;i++) printf "%s0x%s", (n++?",":""), $i}' /tmp/w.txt)
$T setb 0x800002d "$W"                                   # ret 0, Tabelle unverändert
$T setb 0x800002d "9,$(echo $W | cut -d, -f2-)"           # errno 1 (Gewicht >= 9)
$T getptr 0x800002d 225 | diff - /tmp/w.txt && echo gleich
$T getptr 0x8000031 1024 | head                          # 256 x u32 Rohhistogramm, nicht alles 0
$T getptr 0x800002e 16                                   # 4 Schwellen, 5 x u16 (Summe ~0xffff), 2 Bytes
$T setb 0x800002e 16,64,128,192,0,0,0,0,0,0,0,0,0,0,0,0  # ret 0
$T set 0x800002e 0x10            # ungültiger Userpointer: errno 14 (EFAULT), KEIN Oops
dmesg | tail
```

### 5.12 B11: Gamma sofort wirksam

Ändert das Bild kurz leicht.

```sh
$T getptr 0x800002b 258 > /tmp/g.txt
G=$(awk '{for(i=1;i<=NF;i++) printf "%s0x%s", (n++?",":""), $i}' /tmp/g.txt)
devmem 0x13340000 32; devmem 0x13340004 32
$T setb 0x800002b "$G"; devmem 0x13340000 32     # unverändert
```

`G2` bilden: dieselbe Liste, aber das dritte Element (Byte 2 = unteres Byte
von `lut[1]`) um 0x10 erhöht, ohne Überlauf über 0xff (sonst ein anderes
kleines Element nehmen). Die Umrechnung am besten in der lokalen Session
erledigen, busybox-awk rechnet nicht zuverlässig mit Hex.

```sh
$T setb 0x800002b "$G2"; devmem 0x13340000 32    # Bits 12..23 sofort geändert, ohne Tag/Nacht-Wechsel
$T setb 0x800002b "$G"; devmem 0x13340000 32     # wieder Ausgangswert
```

Das Register enthält `lut[1] << 12 | lut[0]`.

### 5.13 B10: manuelle CCM

Ändert kurz die Farbsättigung (Stock-Verhalten: im kombinierten Pfad geht das
Sättigungsflag an BCSH, die CCM-Sättigung wird auf 1.0 gesetzt).

```sh
$T getptr 0x8000100 40                          # Ausgangsattribut
for a in 0x13305004 0x13305008 0x1330500c 0x13305010 0x13305014; do devmem $a 32; done
```

Aus den Registern die aktuelle Matrix bilden: `0x5004 = m1<<16|m0`,
`0x5008 = m3<<16|m2`, `0x500c = m5<<16|m4`, `0x5010 = m7<<16|m6`,
`0x5014 = m8` (je 16 Bit). Dann manuell setzen (Wort 0 = Byte 0 manuell,
Byte 1 Sättigungsflag):

```sh
$T setptr 0x8000100 0x0101,m0,m1,m2,m3,m4,m5,m6,m7,m8
for a in 0x13305004 0x13305008 0x1330500c 0x13305010 0x13305014; do devmem $a 32; done
```

Erwartet: die Register entsprechen m0..m8 (höchstens Rundung) und bleiben
auch bei Lichtwechsel konstant (vorher: Tuning-D-Matrix, Nutzerwerte ignoriert).
`$T getptr 0x8000100 40` zeigt Byte 0 = 01. Zurück auf Automatik:

```sh
$T setptr 0x8000100 0
```

### 5.14 B13: SetAeAttr (manuelle Belichtung)

Ändert die Bildhelligkeit, solange aktiv.

```sh
$T expr                                          # aktuelles it merken
$T getptr 0x8000035 152 | head -2                # Kontrollobjekt, Wort 0 = 0 (auto)
$T setptr 0x8000035 1,0x800,0x400,<it>,0x400     # manuell: IT=<it>, again 2x, dgains 1x
sleep 2; $T expr                                 # it == <it>, bleibt stehen
$T getptr 0x8000026 24                           # again-Feld ≈ 32 (log2, 2x)
$T setptr 0x8000035 0                            # zurück auf Automatik (alle Flags 0)
sleep 3; $T expr                                 # AE regelt wieder
```

Vorher fror AE nur ein, ohne die Werte zu übernehmen.

## 6. Abschluss

```sh
$T set 0x8000034 0      # falls AE noch eingefroren ist
reboot                  # lädt wieder das Modul aus dem Flash
```

Nach dem Neustart prüfen, dass `/tmp` leer ist und der Streamer normal läuft.

## 7. Ergebnisprotokoll (Vorlage)

| Test | Bug | Erwartung | Ergebnis | Notiz |
|---|---|---|---|---|
| 5.1 | Logging | keine `Set control:`-Zeilen | | |
| 5.2 | B7/B15 | nur Nullen bzw. echte Zonenwerte | | |
| 5.3 | B2/B3 | it_max = Kappe, it ≤ Kappe, EINVAL bei 0, AeMin wirkt | | |
| 5.4 | B14 | EPERM bei 0xffffffff | | |
| 5.5 | B12 | EINVAL bei -1 und 3 | | |
| 5.6 | Lücke 8 | neue T31_DEFLICK-Zeile nach FPS-Wechsel | | |
| 5.7 | B9 | Register unverändert beim Rückschreiben | | |
| 5.8 | B4 | X, X gleich; 128 = Ausgangswert | | |
| 5.9 | B5 | sofort wirksam; X, X gleich; 128 = Ausgang | | |
| 5.10 | B6 | ret 0, Getter stimmt | | |
| 5.11 | B8/B17 | 225 Gewichte, Round-Trip, EFAULT ohne Oops | | |
| 5.12 | B11 | LUT-Register sofort geändert und zurück | | |
| 5.13 | B10 | Register = Nutzermatrix, Automatik zurück | | |
| 5.14 | B13 | IT/Gain fest, Automatik zurück | | |

Zusätzlich festhalten: Kameramodell, Sensor, Streamer, `uname -r`,
Commit-Hash des Branches und alle `dmesg`-Auffälligkeiten.
