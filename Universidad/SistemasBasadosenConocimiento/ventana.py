#Importaciones necesarias y widgets de PyQt5
import sys
from PyQt5.QtWidgets import QApplication, QWidget

def main(): #Funcion main del programa
    app=QApplication(sys.argv)  #Objeto de aplicacion
    w=QWidget()     #Widget para interfaz de usuario
    w.resize(250, 150)  #Redimensionar tamaño ventana
    w.move(300, 300)    #Posicionar la ventana en las coordenadas x=300, y=300
    w.setWindowTitle('Simple')  #Titulo ventana
    w.show()    #Mostrar ventana tras su creacion
    sys.exit(app.exec_())   #Salida del bucle (Cierre de ventana)
    
if __name__=='__main__': #Llamada funcion main
    main()
    