#!/bin/bash
if [ $# -ne 1 ];
then
	echo "Error"
	exit 1
fi
contador_c=0
contador_h=0
for x in $(find $1 -name "*.c")
do
	let contador_c=$contador_c+1
done
for x in $(find $1 -name "*.h")
do
	let contador_h=$contador_h+1
done
echo "Tenemos $contador_c ficheros con extension .c y $contador_h ficheros con extension .h"
echo -e "\n"
for x in $(find $1 -name "*.c" && find -name "*.h")
do 
	echo "El fichero $x tiene $(cat $x | wc -l) lineas y $(cat $x | wc -m) caracteres"
done | sort -nr -k8
