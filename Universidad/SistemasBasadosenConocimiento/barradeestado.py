#Importaciones necesarias y widgets de PyQt5
import sys
from PyQt5.QtWidgets import QMainWindow, QApplication

class BarraEstado(QMainWindow): #Clase Ejemplo de Barra de Estado
    def __init__(self): #Iniciar 
        super().__init__()
        self.initUI()
    def initUI(self):
        self.statusBar().showMessage('Ready') #Barra de estado
        self.setGeometry(300, 300, 250, 150)
        self.setWindowTitle('Statusbar')
        self.show()
        
def main(): #Funcion main
    app=QApplication(sys.argv)
    ex=BarraEstado()
    sys.exit(app.exec_())
    
if __name__ == '__main__': #Llamada función main
    main()