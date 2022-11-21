#Importaciones necesarias y widgets de PyQt5
import sys
from PyQt5 import QtWidgets
import vistaEditor as vista

#Funcion main del programa
app=QtWidgets.QApplication(sys.argv) 
form=vista.vistaEditor()  
sys.exit(app.exec_())