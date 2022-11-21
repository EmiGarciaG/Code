# -*- coding: utf-8 -*-
"""
Created on Wed Mar 23 08:34:53 2022

@author: emili
"""
#Importaciones necesarias para el programa
import sys
import os
from PyQt5.QtWidgets import * 
from PyQt5.QtGui import QIcon
from PyQt5 import QtCore, QtWidgets
import controladorEditor as controlador
from pathlib import Path
import linecache as lc


class vistaApp(QWidget): #Clase vistaApp
    def __init__(self):
        super(vistaApp, self).__init__()
        self.setMinimumSize(800, 600)
        self.setWindowTitle(self.tr("Base de datos alumnos"))
        self.editor=QTextEdit("Nombre\tApellidos\tCalificacion")
        self.lista=QListWidget()
        self.line1=QLineEdit("")
        self.line2=QLineEdit("")
        self.line3=QLineEdit("")
        self.line4=QLineEdit("")
        
        #Botones, lineas, etc
        direc=QLabel("Directorio de archivos")
        select=QPushButton("Seleccionar")
        archivos=QLabel("Archivos")
        alumno=QPushButton("Insertar Alumno")
        nombre=QLabel("Nombre")
        apellidos=QLabel("Apellidos")
        calificacion=QLabel("Calificación")
        guardar=QPushButton("Guardar")
        guardarComo=QPushButton("Guardar Como")
        aprobados=QPushButton("Alumnos aprobados")
        media=QPushButton("Media calificaciones")
        
        #Grid
        grid=QGridLayout(self)
        grid.addWidget(direc, 1, 1, 1, 1)
        grid.addWidget(self.line1, 1, 2, 1, 24)
        grid.addWidget(select, 1, 26, 1, 4)
        grid.addWidget(archivos, 3, 1, 1, 4)
        grid.addWidget(nombre, 3, 7, 1, 4)
        grid.addWidget(apellidos, 4, 7, 1, 4)
        grid.addWidget(calificacion, 5, 7, 1, 4)
        grid.addWidget(alumno, 4, 30, 1, 2)
        grid.addWidget(self.line2, 3, 9, 1, 20)
        grid.addWidget(self.line3, 4, 9, 1, 20)
        grid.addWidget(self.line4, 5, 9, 1, 20)
        grid.addWidget(self.editor, 6, 9, 8, 20)
        grid.addWidget(self.lista, 4, 1, 10, 2)
        grid.addWidget(guardar, 15, 1, 2, 1)
        grid.addWidget(guardarComo, 15, 2, 2, 2)
        grid.addWidget(aprobados, 15, 4, 2, 2)
        grid.addWidget(media, 15, 6, 2, 2)
        
        #Botones
        select.clicked.connect(self.elegirDir)
        alumno.clicked.connect(self.insertar)
        self.lista.itemDoubleClicked.connect(self.editarArchivo)
        guardar.clicked.connect(self.save)
        guardarComo.clicked.connect(self.saveAs)
        
        #aprobados.clicked.connect(self.passed)
        #media.clicked.connect(self.average)
    
    
    #Funcion elegirDir
    def elegirDir(self):
        global path
        path=str(QFileDialog.getExistingDirectory(self, "Escoger Directorio"))
        self.line1.setText(path)
        ficheros=[f for f in os.listdir(str(path)) if os.path.isfile(os.path.join(str(path), f))]
        self.lista.clear()
        for item in ficheros:
            self.lista.addItem(item)
            
    #Funcion save        
    def save(self):
        fila=self.lista.currentRow()
        item=self.lista.item(fila)
        fichero=item.text()
        directorio=self.line1.text()
        ficheroRuta=os.path.join(str(directorio), str(fichero))
        texto=self.editor.toPlainText()
        controlador.guardadoC(ficheroRuta, texto)
            
    #Funcion saveAs    
    def saveAs(self):
        new_file_path, filter_type=QFileDialog.getSaveFileName(self, "Guardar el archivo como")
        fichero=new_file_path
        text=self.editor.toPlainText()
        controlador.guardadoC(fichero, text)
        ficheros=[f for f in os.listdir(str(path)) if os.path.isfile(os.path.join(str(path), f))]
        self.lista.clear()
        for item in ficheros:
            self.lista.addItem(item)
            
    #Funcion insertar       
    def insertar(self):
        dato1=self.line2.text()
        dato2=self.line3.text()
        dato3=self.line4.text()
        inf=dato1+" "+dato2+" "+dato3
        print(inf)
        if len(dato1)!=0 and len(dato2)!=0 and len(dato3)!=0 and dato3.isdigit() and int(dato3)<11:
            self.editor.append(inf)
        else:
            pass
        
    #Funcion editarArchivo    
    def editarArchivo(self):
        fila=self.lista.currentRow()
        item=self.lista.item(fila)
        fichero=item.text()
        directorio=self.line1.text()
        self_path=os.path.join(str(directorio), str(fichero))
        texto=controlador.leer(self_path)
        self.editor.setText(texto)
            
#Llamada funcion main            
if __name__=='__main__':
    app=QApplication([])
    w=vistaApp()
    w.show()
    sys.exit(app.exec_())