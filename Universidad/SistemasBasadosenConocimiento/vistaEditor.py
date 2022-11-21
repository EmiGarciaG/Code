#Importaciones necesarias y widgets de PyQt5
#Importaciones necesarias y widgets de PyQt5
import sys
import os
from PyQt5 import QtWidgets
from PyQt5.QtWidgets import QWidget, QTextEdit, QListWidget, QLineEdit, QLabel, QPushButton, QGridLayout, QFileDialog, QApplication 
import controladorEditor as controlador
from pathlib import Path

class vistaEditor(QWidget): #Clase vistaEditor 
    #Visualizacion
    def __init__(self):
        super(vistaEditor, self).__init__()
        self.setWindowTitle(self.tr("Editor de texto"))
        self.editor=QTextEdit("")
        self.lista=QListWidget()
        self.line=QLineEdit("")
        direc=QLabel("Carpeta")
        select=QPushButton("Seleccionar")
        archivos=QLabel("Archivos")
        guardar=QPushButton("Guardar")
        guardarComo=QPushButton("Guardar Como")
        grid=QGridLayout(self)
        grid.addWidget(direc, 1, 1, 1, 1)
        grid.addWidget(self.line, 1, 2, 1, 24)
        grid.addWidget(select, 1, 26, 1, 4)
        grid.addWidget(archivos, 3, 1, 1, 4)
        grid.addWidget(self.editor, 5, 7, 8, 20)
        grid.addWidget(self.lista, 5, 1, 8, 6)
        grid.addWidget(guardar, 17, 1, 2, 3)
        grid.addWidget(guardarComo, 17, 4, 2, 5)
        select.clicked.connect(self.elegirDir)
        self.lista.itemDoubleClicked.connect(self.editarArchivo)
        guardar.clicked.connect(self.save)
        guardarComo.clicked.connect(self.saveAs)
    
    #Funciones Editor
    def elegirDir(self):
        global path
        path=str(QFileDialog.getExistingDirectory(self, "Escoger Directorio"))
        self.line.setText(path)
        files=[f for f in os.listdir(str(path)) if os.path.isfile(os.path.join(str(path), f))]
        self.lista.clear()
        for item in files:
            self.lista.addItem(item)
                
    def editarArchivo(self):
        fila=self.lista.currentRow()
        item=self.lista.item(fila)
        fichero=item.text()
        directorio=self.line.text()
        self_path=os.path.join(str(directorio), str(fichero))
        text=controlador.readEvent(self_path)
        self.editor.setText(text)
            
    def save(self):
        fila=self.lista.currentRow()
        item=self.lista.item(fila)
        fichero=item.text()
        directorio=self.line.text()
        fileNameAbs=os.path.join(str(directorio), str(fichero))
        text=self.editor.toPlainText()
        controlador.saveAsEvent(fileNameAbs, text)
            
    def saveAs(self):
        new_file_path, filter_type=QFileDialog.getSaveFileName(self, "Guardar el archivo como")
        fichero=new_file_path
        text=self.editor.toPlainText()
        controlador.saveAsEvent(fichero, text)
        files=[f for f in os.listdir(str(path)) if os.path.isfile(os.path.join(str(path), f))]
        self.lista.clear()
        for item in files:
            self.lista.addItem(item)
            
#Llamada funcion main            
if __name__=='__main__':
    app=QApplication([])
    w=vistaEditor()
    w.show()
    sys.exit(app.exec_())

