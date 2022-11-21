# -*- coding: utf-8 -*-
"""
Created on Wed Mar 23 08:34:05 2022

@author: emili
"""
#Importaciones necesarias para el programa
import modeloApp as modelo

def guardado(fichero, texto):
    modelo.saveAlumno(fichero, texto)
    
def guardadoC(fichero, texto):
    modelo.saveAlumno(fichero, texto)
    
def leer(fichero):
    texto=modelo.readText(fichero)
    return texto