#Importaciones necesarias y widgets de PyQt5
import sys
from PyQt5.QtWidgets import QWidget, QLabel, QApplication

class Position(QWidget):    #Clase Position
    def __init__(self):
        super().__init__()
        self.initUI()
    def initUI(self):   #Posicionamientos absolutos
        lbl1=QLabel('Esto', self)
        lbl1.move(15, 10)
        lbl2=QLabel('es un', self)
        lbl2.move(35, 40)
        lbl3=QLabel('mensaje', self)
        lbl3.move(55, 70)
        self.setGeometry(300, 300, 250, 150)
        self.setWindowTitle('Absolute')
        self.show()
        
def main(): #Funcion main del programa
    app=QApplication(sys.argv)
    ex=Position()
    sys.exit(app.exec_())
    
if __name__ == '__main__':  #Llamada funcion main
    main()