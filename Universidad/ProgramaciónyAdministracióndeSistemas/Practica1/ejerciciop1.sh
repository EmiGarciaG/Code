#!/bin/bash
if [ $# -ne 1 ];
then
	echo "ERROR"
	exit 1
fi
for x in $(find $1 -name "*")
do
	nombre=$(basename $x)
	len=$(echo -n $nombre | wc -c)
	if [ $len -eq 1 ];
	then
		echo "$nombre <- $len caracter"
	else
		echo "$nombre <- $len caracteres"
	fi
done
echo "........."
for x in $(find $1 -name "*")
do
	nombre=$(basename $x)
	len=$(echo -n $nombre | wc -c)
	let paridad=$len%2
	if [ $paridad -eq 1 ];
	then
		kylobytes=$(stat -c "%s" $x)
		let kb=$kylobytes/1024
		echo "$nombre, $(find $PWD -name "$1"), i-nodo $(stat -c "%i" $x), $(stat -c "%s" $x) bytes ($kb kB), permisos: $(stat -c "%a" $x) ($(stat -c "%U" $x ) : $(stat -c "%G" $x ))"
	fi
done 

