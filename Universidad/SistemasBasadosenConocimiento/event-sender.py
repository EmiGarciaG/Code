#Importaciones necesarias y widgets de PyQt5
import sys
from PyQt5.QtWidgets import QMainWindow, QPushButton, QApplication


class EventS(QMainWindow):
    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self):
        btn1=QPushButton("Botón 1", self)
        btn1.move(30, 50)
        btn2=QPushButton("Botón 2", self)
        btn2.move(150, 50)
        btn1.clicked.connect(self.buttonClicked)
        btn2.clicked.connect(self.buttonClicked)
        self.statusBar()
        self.setGeometry(300, 300, 450, 350)
        self.setWindowTitle('Event sender')
        self.show()

    def buttonClicked(self): #Imprimir boton presionado
        sender = self.sender()
        self.statusBar().showMessage(sender.text() + ' ha sido presionado')


def main(): #Funcion main del programa
    app=QApplication(sys.argv)
    ex=EventS()
    sys.exit(app.exec_())

if __name__ == '__main__': #Llamada funcion main
    main()
