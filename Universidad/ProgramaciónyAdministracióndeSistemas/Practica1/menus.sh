#!/bin/bash
mostrarInfo(){
	echo "=== Menu principal ==="
	echo "Selecciona una opcion:"
	echo "1. Opcion 1"
	echo "2. Opcion 2"
	echo "3. Opcion 3"
	echo "4. Opcion 4 Submenu"
	echo "9. Cancelar"
	echo "0. Confirmar"
}

submenu(){
	echo "=== Acceso submenu ==="
	echo "1. Submenu opcion 1"
	echo "2. Submenu opcion 2"
	echo "3. Submenu opcion 3"
	
	read tipo
	
	case $tipo in
		1)
			echo "Ha seleccionado Submenu opcion 1";;
		2)
			echo "Ha seleccionado Submenu opcion 2";;
		3)
			echo "Ha seleccionado Submenu opcion 3";;
		*)
			echo "Ha seleccionado otra opcion";;
	esac
}
clear
mostrarInfo
while read val; do
	clear
	case $val in
		1)
			echo "Ha seleccionado opcion 1";;
		2)
			echo "Ha seleccionado opcion 1";;
		3)
			echo "Ha seleccionado opcion 1";;
		4)
			submenu;;
		9)
			exit;;
		0)
			echo "Confirmacion"
			exit;;
	esac
	echo "================================="
	mostrarInfo
done
