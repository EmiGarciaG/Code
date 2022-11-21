#Importaciones necesarias
import modeloEditor as modelo

#Funcion de guardado
def saveEvent(fileName, text):
    modelo.saveText(fileName, text)

#Funcion de guardado como    
def saveAsEvent(fileName, text):
    modelo.saveText(fileName, text)
    
#Funcion de abrir archivo    
def readEvent(fileName):
    text=modelo.readText(fileName)
    return text