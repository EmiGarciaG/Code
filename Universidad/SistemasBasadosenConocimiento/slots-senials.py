#Importaciones necesarias y widgets de PyQt5
import sys
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import (QWidget, QLCDNumber, QSlider,
                             QVBoxLayout, QApplication)

class SlotsSenials(QWidget): #Clase SlotsSenials
    def __init__(self):
        super().__init__()
        self.initUI()
    def initUI(self):
        lcd=QLCDNumber(self)    #Mostrar numero
        sld=QSlider(Qt.Horizontal, self)  #Controlador  
        vbox=QVBoxLayout()  #Recuadro
        vbox.addWidget(lcd) 
        vbox.addWidget(sld)
        self.setLayout(vbox)
        sld.valueChanged.connect(lcd.display)   #Conectar manejador
        self.setGeometry(300, 300, 250, 150)
        self.setWindowTitle('Señal y slot')
        self.show()
        
def main(): #Funcion main
    app=QApplication(sys.argv)
    ex=SlotsSenials()
    sys.exit(app.exec_())
    
if __name__ == '__main__':  #Llamada al main
    main()