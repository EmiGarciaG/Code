#Importaciones necesarias y widgets de PyQt5
import sys
from PyQt5.QtWidgets import QWidget, QMessageBox, QApplication

class MessageBox(QWidget): #Clase MessageBox
    def __init__(self):
        super().__init__()
        self.initUI()
        
    def initUI(self):#Ventana
        self.setGeometry(300, 300, 250, 150)
        self.setWindowTitle('Message box')
        self.show()
        
    def closeEvent(self, event):#Preguntar por cierre
        reply = QMessageBox.question(self, 'Message', "Are you sure to quit?", QMessageBox.Yes | QMessageBox.No, QMessageBox.No)
        if reply == QMessageBox.Yes:
            event.accept()
        else:
            event.ignore()
            
def main(): #Funcion main del programa
    app=QApplication(sys.argv)
    ex=MessageBox()
    sys.exit(app.exec_())
    
if __name__ == '__main__': #Llamada funcion main
    main()