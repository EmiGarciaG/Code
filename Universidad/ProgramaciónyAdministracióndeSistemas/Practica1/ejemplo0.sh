#!/bin/bash
if [ $# -ne 1 ];
then
	echo "ERROR"
	echo -e "\n"
	exit 1
fi
if [ ! -d "$1" ]
then
	echo " El argumento no es un directorio"
	echo -e "\n"
	exit 1
fi
echo "Argumentos introducidos : \n\t <nombre directorio> : $1"
