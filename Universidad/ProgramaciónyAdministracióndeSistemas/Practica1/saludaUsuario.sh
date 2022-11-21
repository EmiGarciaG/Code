#!/bin/bash
echo -n "Introduzca su nombre de usuario: "
read user
if [ "$user" == "$USER" ];
then 
echo "Bienvenido $USER"
else
echo "Eso es mentira!"
fi
