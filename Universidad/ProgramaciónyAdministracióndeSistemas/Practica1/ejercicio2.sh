#!/bin/bash

if [ $# -eq 0 ] || [ $# -ge 3 ];
then
	echo "ERROR"
	exit 1
else 
	if [ $# -eq 1 ];
	then
		tam=0
	else
		tam=$2
	fi
intro=0
for x in $(find $1 -size "$tam"c -or -size +"$tam"c)
do
	if [ "$intro" -eq 0 ];
	then
		echo "Nombre; LongitudUsuario; FechaModificacion; FechaAcceso; Tamaño; Bloques; Permisos; Ejecutable"
	fi
	if [ -x $x ];
	then
		ejecutable=1
	else 
		ejecutable=0
	fi
	nombre=$(basename $x)
	let longitudUsuario=$(stat -c "%U" $x | wc -m)-1
	fechamModificacion=$(stat -c "%y" $x)
	fechaAcceso=$(stat -c "%x" $x)
	tamano=$(stat -c "%s" $x)
	nBloques=$(stat -c "%b" $x)
	permisos=$(stat -c "%A" $x)
	echo "$nombre; $longitudUsuario; $fechaModificacion; $fechaAcceso; $tamano; $nBloques; $permisos; $ejecutable"
done | sort -n -k5 -t ";" | tee salidaEjemplo2.txt
fi
	
