#Importaciones necesarias y widgets de PyQt5
import sys
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QMainWindow, QDesktopWidget, QTextEdit, QMenu, QAction, QApplication, QMessageBox
from PyQt5.QtGui import QIcon

class App(QMainWindow): #Clase App
    def __init__(self):
        super().__init__()
        self.initUI()
        
    def initUI(self):
        textEdit=QTextEdit()
        self.setCentralWidget(textEdit)
        exitAct=QAction(QIcon('exit.png'), 'Salir', self)
        exitAct.setShortcut('Ctrl+Q')
        exitAct.setStatusTip('Salir de la aplicacion')
        exitAct.triggered.connect(self.close)
        self.statusBar()
        menubar=self.menuBar()
        fileMenu=menubar.addMenu('&Archivo')
        newAct=QAction('Nuevo', self)
        newAct.setShortcut('Ctrl+X')
        newAct.setStatusTip('Nuevo')
        OpMenu=QMenu('Abrir', self) #Menu
        OpAct1=QAction('Carpeta', self) #Submenu
        OpAct1.setShortcut('Ctrl+O')
        OpAct2=QAction('Archivo', self) #Submenu
        OpAct2.setShortcut('Ctrl+A')
        OpAct1.setStatusTip('Abrir Carpeta')
        OpAct2.setStatusTip('Abrir Archivo')
        OpMenu.addAction(OpAct1)
        OpMenu.addAction(OpAct2)
        fileMenu.addAction(newAct)
        fileMenu.addMenu(OpMenu)
        fileMenu.addAction(exitAct)
        toolbar=self.addToolBar('Salir')
        toolbar.addAction(exitAct)
        self.resize(700, 500)
        self.center()
        self.setWindowTitle('Aplication')
        self.show()
        
    def contextMenuEvent(self, event): #Se realiza click derecho
        cmenu=QMenu(self) #Desplegar opciones
        newAct=cmenu.addAction("Nuevo Acceso Directo") 
        openAct=cmenu.addAction("Mover Acceso Directo")
        eraseAct=cmenu.addAction("Eliminar Acceso Directo")
        action=cmenu.exec_(self.mapToGlobal(event.pos())) 
        
    def center(self):   #Centrado de ventana
        qr=self.frameGeometry()
        cp=QDesktopWidget().availableGeometry().center()
        qr.moveCenter(cp)
        self.move(qr.topLeft())
        
    def keyPressEvent(self, e): #Capturador de señal
        if e.key()==Qt.Key_Escape:
            self.close()
            
    def closeEvent(self, event):    #Mensaje de confirmar cierre
        reply=QMessageBox.question(self, 'Mensaje', "¿Seguro que quieres salir?", QMessageBox.Yes | QMessageBox.No, QMessageBox.No)
        if reply==QMessageBox.Yes:
            event.accept()
        else:
            event.ignore()
        
def main(): #Funcion main del programa
    app=QApplication(sys.argv)
    ex=App()
    sys.exit(app.exec_())
    
if __name__ == '__main__': #Llamada funcion main
    main()