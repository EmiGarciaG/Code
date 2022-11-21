#Importaciones necesarias y widgets de PyQt5
import sys
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QWidget, QApplication, QGridLayout, QLabel


class Coordenada(QWidget): #Clase Coordenada
    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self):
        grid=QGridLayout()
        x=0
        y=0
        self.text=f'x: {x},  y: {y}' #Coordenadas
        self.label=QLabel(self.text, self)
        grid.addWidget(self.label, 0, 0, Qt.AlignTop)
        self.setMouseTracking(True) #Seguimiento del raton
        self.setLayout(grid)
        self.setGeometry(300, 300, 450, 300)
        self.setWindowTitle('Objeto de evento')
        self.show()

    def mouseMoveEvent(self, e):
        x=e.x()
        y=e.y()
        text=f'x: {x},  y: {y}' 
        self.label.setText(text) #Escribir coordenadas en pantalla


def main(): #Funcion main del programa
    app=QApplication(sys.argv)
    ex=Coordenada()
    sys.exit(app.exec_())

if __name__ == '__main__': #Llamada funcion main
    main()