#!/bin/bash
cat /etc/passwd | grep -v '^#' | sed -n 'n;p' | awk -F: '{print $1}' | rev | sort -r | awk -v ln1=$FT_LINE1 -v ln2=$FT_LINE2 'NR>=ln1&&NR<=ln2' | xargs |sed 's/ /, /g' | sed 's/$/./' | tr -d '\n'
