#Importaciones necesarias y widgets de PyQt5
import sys
from PyQt5.QtWidgets import QMainWindow, QAction, QMenu, QApplication


class SubMenu(QMainWindow): #Clase SubMenu 
    def __init__(self):
        super().__init__()
        self.initUI()
    def initUI(self):
        menubar=self.menuBar()
        fileMenu=menubar.addMenu('Archivo') #Barra de menu
        impMenu=QMenu('Importar', self) #Menu
        impAct=QAction('Importar email', self) #Submenu
        impMenu.addAction(impAct)
        newAct=QAction('Nuevo', self)
        fileMenu.addAction(newAct)
        fileMenu.addMenu(impMenu)
        self.setGeometry(300, 300, 300, 200)
        self.setWindowTitle('Submenu')
        self.show()
        
def main():   #Funcion main
    app=QApplication(sys.argv)
    ex=SubMenu()
    sys.exit(app.exec_())
    
if __name__ == '__main__':    #Llamada al main
    main()