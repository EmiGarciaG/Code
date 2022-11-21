#!/bin/bash
echo -n "Introduzca un número (1<=x<10): "
read x
if [ "$x" -ge 1 ] && [ "$x" -lt 10 ];
then
echo "El número $x es correcto!"
else
echo "Fuera de rango!"
fi
