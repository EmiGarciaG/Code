#!/bin/bash
#2.Desarrolla un script que reciba como argumentos obligatorios un directorio y un número entero N . El script deberá dividir los ficheros que se encuentren 
#dentro de dicho directorio en N partes iguales por orden alfabético. Los subdirectorios no se tomarán en cuenta, ni tampoco los ficheros que se encuentren dentro 
#de los subdirectorios. Cada grupo de ficheros se copiará en una carpeta diferente cuyo nombre incluirá el número del grupo correspondiente. Si el número
#de ficheros es demasiado pequeño como para hacer N grupos, el script deberá devolver un error y no hacer nada.
#Nota: para dividir una lista de ficheros en grupos de tamaño N puedes utilizar el comando xargs -n $N. Si lo necesitas, busca algo más de información acerca de este comando.
#Un ejemplo de ejecución serı́a el siguiente:

if [ -d ${1} ] && [ ${2} -gt 0 ]
then
    echo "Empezamos:"
    for c in $(ls ${1})
	do
	    let "x = $x + 1"
	done
    if [ ${2} -gt $x ] || [ $[x%${2}] -ne 0 ]
    then
        echo "[ERROR] es imposible dividir $x archivos en ${2} grupos"
        exit    
    else
        echo "Hay un total de $x ficheros y directorios a dividir en ${2} grupos en ${1}"
    fi
else
    echo "Debes introducir el comando tal que ./ejecutable directorio int_gt0"
    exit
fi

#Despues de esta seccion de comprobaciones, comenzamos a crear las carpetas donde
# dividir los archivos

let size=$[x/${2}]
echo "Los grupos deberán tener un tamano de $size"

mkdir grupos
for count in $( seq ${2} )
do 
    mkdir "grupos/grupo$count"
done

i=0
for x in $( ls ${1} )
    do
        cp $1$x grupos/grupo$[i/$size+1]
        let "i = $i + 1"
done
