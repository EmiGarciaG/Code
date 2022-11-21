#Importaciones necesarias y widgets de PyQt5
import sys
from PyQt5.QtWidgets import (QWidget, QToolTip, QPushButton, QApplication)
from PyQt5.QtGui import QFont

class AyudaEmergente(QWidget): #Clase para mostrar la informacion por pantalla
    def __init__(self):
        super().__init__()
        self.initUI()
    def initUI(self):
        QToolTip.setFont(QFont('SansSerif', 10)) #Fuente
        self.setToolTip('Esto es un <b>QWidget</b> widget') #Método para mostrar informacion
        btn = QPushButton('Boton', self) #Boton
        btn.setToolTip('Esto es un <b>QPushButton</b> widget')
        btn.resize(btn.sizeHint()) #Asignar tamaño adecuado al boton
        btn.move(50, 50)
        self.setGeometry(300, 300, 300, 200)
        self.setWindowTitle('Tooltips')
        self.show()
        
def main(): #Funcion main
    app=QApplication(sys.argv)
    ex=AyudaEmergente()
    sys.exit(app.exec_())
    
if __name__ == '__main__': #Llamada a funcion main
    main()