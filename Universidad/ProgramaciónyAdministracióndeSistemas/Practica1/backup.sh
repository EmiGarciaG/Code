#!/bin/bash
if [ "$#" != 1 ];
then 
	echo "El uso del programa es ./backup.sh nombreFichero"
	exit
else
	if [ -f "$1" ];
	then
		fecha=$(date +%d-%m-%y)
		cp "$1" "$1.bak_$fecha"
	else
		echo "El fichero no existe: $1"
		exit
	fi
fi
