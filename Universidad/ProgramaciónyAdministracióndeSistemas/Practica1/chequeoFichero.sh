#!/bin/bash
read -p "Introduce el nombre del fichero:" fichero
if [ -e "$fichero" ]
then 
	echo "Existe el fichero"
	if [ -s "$fichero" ]
	then
		echo "El fichero tiene tamaño mayor que cero"
	else 
		echo "El fichero tiene tamaño igual a cero"
	fi
	if [ -f "$fichero" ]
	then
		echo "Es un fichero"
	else
		echo "No es un fichero"
	fi
	if [ -d "$fichero" ]
	then
		echo "Es un directorio"
	else
		echo "No es un directorio"
	fi
	if [ -r "$fichero" ]
	then
		echo "Tienes permiso de lectura"
	else
		echo "No tienes permiso de lectura"
	fi
	if [ -w "$fichero" ]
	then
		echo "Tienes permiso de escritura"
	else
		echo "No tienes permiso de escritura"
	fi
	if [ -x "$fichero" ]
	then
		echo "Tienes permiso de ejecucion"
	else
		echo "No tienes permiso de ejecucion"
	fi
else 
	echo "No existe el fichero"
fi
