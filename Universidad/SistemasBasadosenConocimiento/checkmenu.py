#Importaciones necesarias y widgets de PyQt5
import sys
from PyQt5.QtWidgets import QMainWindow, QAction, QApplication

class CheckMenu(QMainWindow): #Clase CheckMenu
    def __init__(self):
        super().__init__()
        self.initUI()
    def initUI(self):
        self.statusbar=self.statusBar()
        self.statusbar.showMessage('Listo')
        menubar=self.menuBar()
        viewMenu=menubar.addMenu('Ver')
        viewStatAct=QAction('Ver barra de estado', self, checkable=True) #Accion quitar/poner 
                                                                            #barra de estado
        viewStatAct.setStatusTip('Ver barra de estado')
        viewStatAct.setChecked(True)
        viewStatAct.triggered.connect(self.toggleMenu)
        viewMenu.addAction(viewStatAct)
        self.setGeometry(300, 300, 300, 200)
        self.setWindowTitle('Check Menu')
        self.show()
    def toggleMenu(self, state):
        if state:
            self.statusbar.show()
        else:
            self.statusbar.hide()
            
def main(): #Funcion main
    app=QApplication(sys.argv)
    ex=CheckMenu()
    sys.exit(app.exec_())
    
if __name__ == '__main__':  #Llamada al main
    main()