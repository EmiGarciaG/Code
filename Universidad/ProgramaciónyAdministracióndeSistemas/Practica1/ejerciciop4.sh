#!/bin/bash
prt=""
menu(){
	echo "=== Personalización del prompt ==="
	echo "Selecciona una opcion para añadirle al prompt:"
	echo "1. Nombre de Usuario"
	echo "2. Nombre del host"
	echo "3. Ruta completa"
	echo "4. Última parte de la ruta"
	echo "5. Hora"
	echo "6. Fecha"
	echo "7. Cadena literal"
	echo "8. Añadir color y estilo"
	echo "9. Cancelar"
	echo "0. Confirmar"
}
submenu(){
	echo "=== Configurar colores y estilo ==="
	echo "- Tipo de fuente -"
	echo "1. Normal"
	echo "2. Negrita"
	echo "3. Subrayado"
	read tipo
	case $tipo in
		1)
			echo "";;
		2)
			prt="$(tput bold)$prt";;
			#"\e[1mbold\e[0m"
		3)
			prt="$(tput smul)$prt";;
			#"\e[4munderline\e[0m"	
	esac
	echo "- Color de fuente -"
	echo "1. Negro"
	echo "2. Rojo"
	echo "3. Verde"
	echo "4. Amarillo"
	echo "5. Azul"
	echo "6. Blanco"
	read color
	case $color in
		1)
			prt="$(tput setaf 0)$prt";;
			#echo -e "\e[1;30m This is black text \e[0m"
		2)
			prt="$(tput setaf 1)$prt";;
		3)
			prt="$(tput setaf 2)$prt";;
		4)
			prt="$(tput setaf 3)$prt";;
		5)
			prt="$(tput setaf 4)$prt";;
		6)
			prt="$(tput setaf 7)$prt";;
	esac
	echo "- Color de fondo -"
	echo "1. Negro"
	echo "2. Rojo"
	echo "3. Verde"
	echo "4. Amarillo"
	echo "5. Azul"
	echo "6. Blanco"
	read fondo
	case $fondo in
		1)
			prt="$(tput setab 0)$prt";;
		2)
			prt="$(tput setab 1)$prt";;
		3)
			prt="$(tput setab 2)$prt";;
		4)
			prt="$(tput setab 3)$prt";;
		5)
			prt="$(tput setab 4)$prt";;
		6)
			prt="$(tput setab 7)$prt";;
	esac
}
menu
while read val; do
	clear
	case $val in
		1)
			prt="$prt\u";;
		2)
			prt="$prt\h";;
		3)
			prt="$prt\w";;
		4)
			prt="$prt\W";;
		5)
			prt="$prt\t";;
		6)
			prt="$prt\d";;
		7)
			read cadena
			prt="$prt$cadena";;
		8)
			submenu;;
		9)
			exit;;
		0)
			PROMPT_COMMAND="PS1='$prt';unset PROMPT_COMMAND" bash
			exit;;
	esac
	echo "PROMPT ACTUAL: $prt"
	menu
done
