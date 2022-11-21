#Importaciones necesarias y widgets de PyQt5
import sys
from PyQt5.QtWidgets import QMainWindow, QTextEdit, QAction, QApplication
from PyQt5.QtGui import QIcon

class Bloc(QMainWindow): #Clase Bloc
    def __init__(self):
        super().__init__()
        self.initUI()
        
    def initUI(self):
        #Espacio editor de texto
        textEdit=QTextEdit()
        self.setCentralWidget(textEdit)
        exitAct = QAction(QIcon('exit24.png'), 'Exit', self)
        exitAct.setShortcut('Ctrl+Q')
        exitAct.setStatusTip('Exit application')
        exitAct.triggered.connect(self.close)
        self.statusBar()
        menubar=self.menuBar()
        fileMenu=menubar.addMenu('&File')
        fileMenu.addAction(exitAct)
        toolbar=self.addToolBar('Exit')
        toolbar.addAction(exitAct)
        self.setGeometry(300, 300, 350, 250)
        self.setWindowTitle('Main window')
        self.show()
        
def main(): #Funcion main del programa
    app=QApplication(sys.argv)
    ex=Bloc()
    sys.exit(app.exec_())
    
if __name__ == '__main__': #Llamada funcion main
    main()