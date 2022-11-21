#Importaciones necesarias y widgets de PyQt5
import sys
from PyQt5.QtWidgets import QWidget, QDesktopWidget, QApplication

class Center(QWidget): #Clase Center
    def __init__(self):
        super().__init__()
        self.initUI()
    def initUI(self):
        self.resize(250, 150)
        self.center()
        self.setWindowTitle('Center')
        self.show()
    def center(self):
        qr=self.frameGeometry()
        cp=QDesktopWidget().availableGeometry().center()
        qr.moveCenter(cp)
        self.move(qr.topLeft())
        
def main(): #Funcion main del programa
    app=QApplication(sys.argv)
    ex=Center()
    sys.exit(app.exec_())
    
if __name__ == '__main__': #Llamada funcion main
    main()