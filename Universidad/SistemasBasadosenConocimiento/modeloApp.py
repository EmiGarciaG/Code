# -*- coding: utf-8 -*-
"""
Created on Wed Mar 23 08:32:40 2022

@author: emili
"""
#Guardar Alumno
def saveAlumno(fichero, texto):
    f=open(fichero, 'w')
    f.write(texto)
    f.close()
    return True

#Leer Texto fichero
def readText(fichero):
    f=open(fichero, 'r')
    texto=f.read()
    f.close()
    return texto

#Llamada funcion main 
if __name__=="__main__":
    pass