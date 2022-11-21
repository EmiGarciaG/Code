#Importaciones necesarias y widgets de PyQt5
import sys
from PyQt5.QtWidgets import QMainWindow, QAction, qApp, QApplication
from PyQt5.QtGui import QIcon

class Menu(QMainWindow): #Clase Menu 
    def __init__(self):
        super().__init__()
        self.initUI()
    def initUI(self):
        exitAct=QAction(QIcon('exit.png'), '&Salir', self) #Opcion de salida
        exitAct.setShortcut('Ctrl+Q')   #Añadir un atajo
        exitAct.setStatusTip('Salir de la aplicacion')    #Añadir explicacion
        exitAct.triggered.connect(qApp.quit) #Accion
        self.statusBar()
        menubar=self.menuBar()
        fileMenu=menubar.addMenu('&Archivo') #Opcion menu Archivo
        fileMenu.addAction(exitAct)
        self.setGeometry(300, 300, 300, 200)
        self.setWindowTitle('Simple menu')
        self.show()
        
def main(): #Funcion main
    app = QApplication(sys.argv)
    ex=Menu()
    sys.exit(app.exec_())
    
if __name__ == '__main__': #Llamada al main
    main()