# -*- coding: utf-8 -*-
"""
Created on Wed Mar 23 08:30:13 2022

@author: emili
"""
#Importaciones necesarias para el programa
import sys
from PyQt5 import QtWidgets
import vistaApp as vista
#Funcion main del programa
app=QtWidgets.QApplication(sys.argv) 
form=vista.vistaApp()  
sys.exit(app.exec_())