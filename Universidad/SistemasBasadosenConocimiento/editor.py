#Importaciones necesarias y widgets de PyQt5
from PyQt5.QtGui import QFontDatabase
from PyQt5.QtWidgets import QMainWindow, QVBoxLayout, QWidget, QApplication, QAction, QPlainTextEdit, QStatusBar, QFileDialog, QMessageBox
import os 
import sys 
  
class Editor(QMainWindow):  #Clase Editor
    def __init__(self):
        super().__init__()
        self.initUI()
    
    def initUI(self):
        layout=QVBoxLayout()
        #Editor de texto
        self.editor=QPlainTextEdit() 
        fixedfont=QFontDatabase.systemFont(QFontDatabase.FixedFont) 
        fixedfont.setPointSize(12) 
        self.editor.setFont(fixedfont) 
        #Ruta del fichero
        self.path=None
        layout.addWidget(self.editor) 
        container=QWidget() 
        container.setLayout(layout) 
        self.setCentralWidget(container)
        #Barra de estado y menu de opciones
        self.status=QStatusBar() 
        self.setStatusBar(self.status) 
        file_menu=self.menuBar().addMenu("&Fichero") 
        open_file_action=QAction("Abrir fichero", self) 
        open_file_action.setStatusTip("Abrir fichero")
        open_file_action.setShortcut('Ctrl+O')
        open_file_action.triggered.connect(self.file_open) 
        file_menu.addAction(open_file_action) 
        save_file_action=QAction("Guardar", self) 
        save_file_action.setStatusTip("Guardar fichero actual") 
        save_file_action.setShortcut('Ctrl+S')
        save_file_action.triggered.connect(self.file_save) 
        file_menu.addAction(save_file_action) 
        saveas_file_action=QAction("Guardar como", self) 
        saveas_file_action.setStatusTip("Guardar fichero actual como uno especifico")
        saveas_file_action.triggered.connect(self.file_saveas) 
        file_menu.addAction(saveas_file_action)
        #Actualizar titulo fichero y enseñar ventana
        self.update_title() 
        self.show() 
        
    def dialog_critical(self, s): 
        dlg=QMessageBox(self) 
        dlg.setText(s) 
        dlg.setIcon(QMessageBox.Critical) 
        dlg.show() 
    
    def file_open(self): #Abrir fichero
        path, _ =QFileDialog.getOpenFileName(self, "Abrir Fichero", "",  
                             "Text documents(*.txt);All files(*.*)") 
        if path: 
            try: 
                with open(path, 'rU') as f: 
                    text = f.read() 
            except Exception as e: 
                self.dialog_critical(str(e)) 
            else: 
                self.path=path 
                self.editor.setPlainText(text) 
                self.update_title() 
    
    def file_save(self): #Guardar fichero
        if self.path is None: 
            return self.file_saveas() 
        self._save_to_path(self.path) 
    
    def file_saveas(self): #Guardar fichero como
        path, _ =QFileDialog.getSaveFileName(self, "Guardar Fichero", "",  
                             "Text documents(*.txt)") 
        if not path:
            return
        self._save_to_path(path) 
    
    def _save_to_path(self, path): #Guardar fichero en ruta
        text=self.editor.toPlainText() 
        try: 
            with open(path, 'w') as f: 
                f.write(text) 
        
        except Exception as e:
            self.dialog_critical(str(e)) 
        
        else:
            self.path = path
            self.update_title() 
            
    def closeEvent(self, event):    #Mensaje de confirmar cierre
        reply=QMessageBox.question(self, 'Mensaje', "¿Seguro que quieres salir?", QMessageBox.Yes | QMessageBox.No, QMessageBox.No)
        if reply==QMessageBox.Yes:
            event.accept()
        else:
            event.ignore()
            
    def update_title(self): #Actualizador del titulo del fichero
        self.setWindowTitle("%s - PyQt5 Notepad" %(os.path.basename(self.path)  
        if self.path else "Sin título")) 
    
    def edit_toggle_wrap(self): 
        self.editor.setLineWrapMode(1 if self.editor.lineWrapMode() == 0 else 0 ) 

def main(): #Funcion main del programa
    app=QApplication(sys.argv) 
    app.setApplicationName("PyQt5-Note") 
    window=Editor() 
    app.exec_() 
    
if __name__ == '__main__': #Llamada funcion main
    main()