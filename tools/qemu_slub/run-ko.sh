#!/bin/bash
# run-ko.sh KO|none NAME [CYCLES] [STREAM_SECS]  -- fresh debug guest, push KO (a tx-isp-t40.ko built against the debug kernel),
# run guest-loop.sh, write q/result-NAME.txt (summary + all BUG/INFO lines) and q/result-NAME.done
D=$(dirname "$(readlink -f "$0")"); KO=$1; NAME=$2; N=${3:-3}; SECS=${4:-15}
$D/restart.sh >/dev/null
python3 $D/qpush.py $D/guest-loop.sh /tmp/guest-loop.sh >/dev/null || { echo push failed; exit 1; }
if [ "$KO" = none ]; then KOG=none; else python3 $D/qpush.py $KO /tmp/isp-test.ko >/dev/null || { echo push failed; exit 1; }; KOG=/tmp/isp-test.ko; fi
python3 $D/qc.py -t $((N*(SECS+25)+60)) "sh /tmp/guest-loop.sh $KOG $N $SECS" > $D/q/result-$NAME.txt 2>&1
python3 $D/qc.py -t 30 "dmesg | grep -a -E 'BUG |INFO:|Oops|Unable to handle|epc' | cut -c1-170" >> $D/q/result-$NAME.txt 2>&1
echo done > $D/q/result-$NAME.done
