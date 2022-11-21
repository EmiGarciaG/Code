#!/bin/bash
echo -n "Introduzca un primer número: "
read x
echo -n "Introduzca un segundo número: "
read y
let suma=x+y
let resta=x-y
let multiplicacion=x*y
let division=x/y
let modulo=x%y
echo "Suma=$suma"
echo "Resta=$resta"
echo "Multiplicación=$multiplicacion"
echo "División=$division"
echo "Módulo=$modulo"

