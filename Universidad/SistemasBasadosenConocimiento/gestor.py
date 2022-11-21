#Importaciones necesarias y widgets de PyQt5
import sys
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QWidget, QApplication

class GestorEventos(QWidget):
    def __init__(self):
        super().__init__()
        self.initUI()
    def initUI(self):
        self.setGeometry(300, 300, 250, 150)
        self.setWindowTitle('GestorEventos')
        self.show()
    def keyPressEvent(self, e): #Capturador de señal
        if e.key()==Qt.Key_Escape:
            self.close()
            
def main(): #Funcion main del programa
    app=QApplication(sys.argv)
    ex=GestorEventos()
    sys.exit(app.exec_())
    
if __name__ == '__main__':  #Llamada funcion main
    main()