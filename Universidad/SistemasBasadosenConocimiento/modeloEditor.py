#Funcion de guardado texto
def saveText(fileName, text):
    f=open(fileName, 'w')
    f.write(text)
    f.close()
    return True

#Funcion lectura texto
def readText(fileName):
    f=open(fileName, 'r')
    text=f.read()
    f.close()
    return text

#Llamada al main
if __name__=='__main__':
    pass