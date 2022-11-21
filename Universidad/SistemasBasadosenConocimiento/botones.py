#Importaciones necesarias y widgets de PyQt5
import sys
from PyQt5.QtWidgets import (QWidget, QPushButton,
                             QHBoxLayout, QVBoxLayout, QApplication)

class Buttons(QWidget):  #Clase Buttons
    def __init__(self):
        super().__init__()
        self.initUI()
    def initUI(self):
        okButton=QPushButton("Ok")
        cancelButton=QPushButton("Cancelar")
        hbox=QHBoxLayout()  #Posicionar horizontalmente
        hbox.addStretch(1)
        hbox.addWidget(okButton)
        hbox.addWidget(cancelButton)
        vbox=QVBoxLayout()  #Posicionar verticalmente
        vbox.addStretch(1)
        vbox.addLayout(hbox)
        self.setLayout(vbox)
        self.setGeometry(300, 300, 300, 150)
        self.setWindowTitle('Buttons')
        self.show()
        
def main(): #Funcion main del programa
    app=QApplication(sys.argv)
    ex=Buttons()
    sys.exit(app.exec_())
    
if __name__ == '__main__':  #Llamada funcion main
    main()

