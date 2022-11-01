# Programación
Trabajos/Ejercicios/Prácticas/Cursos

Control de Versiones Git 
| Commando | Función |
| --- | --- |
| git init | Inicializar repositorio Git |
| git config | Ver la configuración de Git |
| git config --globlal <atributo> <Valor> | Cambiar el valor de una configuración de Git |
| git config --list | Configuración por defecto |
| git config --list --show-origin | Localización de la configuración|
| git status | Visualizar el estado del repositorio, commits realizados y seguimiento de archivos |
| git add <archivo1> | Añadir en el commit los ficheros elegidos (. para seleccionar todos los archivos) |
| git rm --cached <archivo> | Eliminar el archivo de la memoria "Git" |
| git commit (-m) (Mensaje) | Confirmación de los cambios realizados |
| git commit -a(m) (Mensaje) | Realiza el función de git add junto con el commit |
| git log <archivo> | Ver el historial de cambios realizados en el archivo |
| git log --stat | Cambios específicos realizados en los archivos en cada commit (Salir con q si es muy largo)|
| git show <archivo> | Comparación de los cambios realizados en un archivo |
| git diff | Comparación del contenido del add y el actual |
| git diff <codigo commit1> <codigo commit2> | Comparación del contenido guardado en los commits |
| git reset <codigo commit> (--hard/--soft) | Volver a los cambios realizados en ese commit (soft para tener la última versión en add y que nuestro archivo local no se actualice) |
| git checkout <codigo commit> <archivo> | Regresar el archivo a la versión de ese commit |
| git checkout master <archivo> | Última versión del archivo |
| git checkout <rama> | Cambiar la rama en la que se está trabajando |
| git branch | Consultar las ramas existentes y dónde estamos trabajando |
| git branch <nombre> | Creación de una rama alternativa (Los cambios que ocurren en esta rama no se visualizan en las demás, reflejado en el archivo local)|
| git merge <rama> | Fusionar la rama donde se está trabajando con el contenido de otra rama (Vigilar conflictos) |
| git remote (-v) | Ver conexiones remotas (-v para ver fetch y push) |
| git remote add <nombre> <enlace> | Añadir un espacio remoto |
| git remote set-url <nombre> <url> | Cambiar url de remoto |
| git pull <remoto> <rama> | Traer el trabajo del remoto a la rama |
| git pull <remoto> <rama> --allow-unrelated-histories | En el caso de error para traer el README.md |
| git push <remoto> <rama> | Enviar contenido de la rama al remoto |

  
| Conexión con llaves pública y privada | Acciones |
| --- | --- |
| ssh-keygen -t rsa -b 4096 -C "correo" | Creación de la llave |
| eval $(ssh-agent -s) | Servidor ssh funcionando |
| ssh-add "dirección-llave-id_rsa" | Añadir llave privada |
  
