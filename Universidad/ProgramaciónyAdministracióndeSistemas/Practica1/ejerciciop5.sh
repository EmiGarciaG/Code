#!/bin/bash
hash="35d0398f7773bae28a5a05aacb45d00371f36638f54e0f4db4a81fa9e2414f29  -"
p="{{0..9},{A..F}}"
for i in $(seq 1 5); do
	s=""
	for j in $(seq 1 $i); do
		s="$s$p"
	done
	combinaciones=$(eval echo -n $s)
	echo "Probando $(echo $combinaciones | wc -w) combinaciones de longitud $i"
	for c in $combinaciones; do
		h=$(echo $c | sha256sum)
		OLDIFS=$IFS
		IFS="$\n"
		if [ "$h" == "$hash" ]; then
			echo "Se ha encontrado la contraseña:" $c
			exit
		fi
		IFS=$OLDIFS
	done
done

