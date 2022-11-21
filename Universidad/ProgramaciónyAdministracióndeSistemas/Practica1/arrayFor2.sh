#!/bin/bash
read -p "Introduce el numero de valores: " numVal
for (( i=1; $i<=numVal; i=$i+1))
do
	read -p "Introduce el valor de la lista numero $i: " cadVal
	arrayVal[$i]=$cadVal
done
echo "La longitud del array \"${arrayVal[*]}\" es ${#arrayVal[@]}"
