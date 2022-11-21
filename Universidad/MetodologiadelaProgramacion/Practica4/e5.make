#Destino simbolico
todo: crucigrama.x clean

#Regla para construir el ejecutable
crucigrama.x: ficheros.o crucigrama.o main.o libMemoria.a  
    gcc ficheros.o crucigrama.o main.o libMemoria.a -o crucigrama.x

#Regla para construir la biblioteca
libMemoria.a: reservaMemoria.o liberaMemoria.o
    ar -rsv libMemoria.a reservaMemoria.o liberaMemoria.o

#Regla para construir los objetos
reservaMemoria.o: reservaMemoria.c memoria.h
    gcc -c reservaMemoria.c

liberaMemoria.o: liberaMemoria.c memoria.h
    gcc -c liberaMemoria.c

main.o: main.c ficheros.h memoria.h crucigrama.h
    gcc -c main.c

ficheros.o: ficheros.c ficheros.h
    gcc -c ficheros.c

crucigrama.o: crucigrama.c crucigrama.h
    gcc -c crucigrama.c

.PHONY: clean
clean:
    @ echo Borrando ficheros.o
    @ rm *.o
