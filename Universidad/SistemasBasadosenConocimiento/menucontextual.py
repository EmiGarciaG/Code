#Importaciones necesarias y widgets de PyQt5
import sys
from PyQt5.QtWidgets import QMainWindow, qApp, QMenu, QApplication

class ContextMenu(QMainWindow): #Clase ContextMenu
    def __init__(self):
        super().__init__()
        self.initUI()
    def initUI(self):
        self.setGeometry(300, 300, 300, 200)
        self.setWindowTitle('Menu Contextual')
        self.show()
    def contextMenuEvent(self, event): #Se realiza click derecho
        cmenu=QMenu(self) #Desplegar opciones
        newAct=cmenu.addAction("Nuevo") 
        openAct=cmenu.addAction("Abrir")
        quitAct=cmenu.addAction("Salir")
        action=cmenu.exec_(self.mapToGlobal(event.pos()))
        if action==quitAct:
            qApp.quit()
            
def main(): #Funcion main
    app=QApplication(sys.argv)
    ex=ContextMenu()
    sys.exit(app.exec_())
    
if __name__ == '__main__':  #Llamada al main
    main()