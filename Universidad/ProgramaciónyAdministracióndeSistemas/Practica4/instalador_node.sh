#!/bin/bash
mkdir $HOME/node
cd $HOME/node

#descargamos el archivo con el código fuente y lo guardamos en la carpeta /node
sudo wget -O node-v10.15.1-linux-x64.tar.xz https://nodejs.org/dist/v10.15.1/node-v10.15.1-linux-x64.tar.xz

#descomprimimos el archivo en esa la carpeta /opt y borramos el archivo tar.gz que no vamos a usar más
tar -Jxvf node-v10.15.1-linux-x64.tar.xz
rm node-v10.15.1-linux-x64.tar.xz

export PATH=$PATH:$HOME/node/node-v10.15.1-linux-x64/bin

#comprobar que todo se ha instalado correctamente
node --version && npm --version
