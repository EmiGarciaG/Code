#Importaciones necesarias y widgets de PyQt5
import sys
from PyQt5.QtWidgets import QMainWindow, QAction, qApp, QApplication
from PyQt5.QtGui import QIcon

class ToolBar(QMainWindow): #Clase ToolBar
    def __init__(self):
        super().__init__()
        self.initUI()
    def initUI(self):
        exitAct=QAction(QIcon('exit24.png'), 'Salir', self) #Accion salida
        exitAct.setShortcut('Ctrl+Q') #Atajo
        exitAct.triggered.connect(qApp.quit)
        self.toolbar=self.addToolBar('Salir') #Accion salir en toolbar
        self.toolbar.addAction(exitAct)
        self.setGeometry(300, 300, 300, 200)
        self.setWindowTitle('Toolbar')
        self.show()
        
def main(): #Funcion main
    app = QApplication(sys.argv)
    ex =ToolBar()
    sys.exit(app.exec_())
    
if __name__ == '__main__':  #Llamada al main
    main()