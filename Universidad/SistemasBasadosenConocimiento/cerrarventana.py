#Importaciones necesarias y widgets de PyQt5
import sys
from PyQt5.QtWidgets import QWidget, QPushButton, QApplication

class CloseWindow(QWidget): #Clase CloseWindow
    def __init__(self):
        super().__init__()
        self.initUI()
        
    def initUI(self):
        qbtn=QPushButton('Quit', self) #Cierre de ventan
        qbtn.clicked.connect(QApplication.instance().quit)
        qbtn.resize(qbtn.sizeHint())
        qbtn.move(50, 50)
        self.setGeometry(300, 300, 350, 250)
        self.setWindowTitle('Quit button')
        self.show()
        
def main(): #Funcion main del programa
    app=QApplication(sys.argv)
    ex=CloseWindow()
    sys.exit(app.exec_())
    
if __name__ == '__main__': #Llamada funcion main
    main() 