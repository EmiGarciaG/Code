#!/bin/bash

if [ $# != 2 ]
then 
	echo $0 "<fichero> <directorio>"
else 
	if [ -a $1 ]
	then
		echo "$1 existe"
	else 
		echo "$1 no existe"
	fi
	if [ -f $1 ]
	then
		echo "$1 es un fichero"
	else 
		echo "$1 no es un fichero"
	fi
	if [ -a $2 ]
	then
		echo "$2 existe"
	else 
		echo "$2 no existe"
	fi
	if [ -d $2 ]
	then
		echo "$2 es un directorio"
	else
		echo "$2 no es un directorio"
	fi
fi 
