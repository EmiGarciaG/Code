#!/bin/bash
find $1 | while read line; do
	nombre=$(basename $line)
	echo $nombre
done | sort

for f in $(find $1 -name "*sh")
do
	echo "El fichero es $f"
	echo "Basename=$(basename $f)"
	echo "Dirname es $(dirname $f)"
	echo "-------------------------------------------"
done
