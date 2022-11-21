#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
using namespace std;
struct Alumno{
	string dni;
	int edad;
	float nota;
};
int lee(string ruta_fichero, Alumno v[]){
	ifstream file;
	file.open(ruta_fichero);
	if(file.is_open()==false){
		return -1;
	}	
	int z=0;
	while(!file.eof()){
		Alumno aux;
		file>>aux.dni;
		file>>aux.edad;
		file>>aux.nota;
		v[z]=aux;
		z++;
	}
	file.close();
	return z;
}
bool DNI(string& dni){
	int s=dni.size();
	if(s!=9){
		cout<<"El dni debe tener 9 caracteres"<<endl;
		return false;
	}
	for(int i=0; i<s-1; i++){
		if (!isdigit(dni[i])){
			cout<<"Los primeros 8 caracteres deben ser numeros"<<endl;
			return false;
		}
	}
	string letras="TRWAGMYFPDXBNJZSQVHLCKE";
	int num= stoi(dni);
	if(dni[8]!=letras[(num%23)]){
		cout<<"La letra no corresponde con los datos numericos o es minuscula"<<endl;
		return false;
	}
	return true;
}
bool guarda(string ruta_fichero, Alumno v[], int nalumnos){
	ofstream file;
	file.open(ruta_fichero);
	if(!file.is_open()){
		return false;
	}
	for(int i=0; i<nalumnos; i++){
		if(v[i].dni!= ""){
			file<<v[i].dni<<endl;
			file<<v[i].edad<<endl;
			file<<v[i].nota<<endl;
		}
	}
	file.close();
	return true;
}
void impalumno(int a){
	for(int k=1; k<=a; k++){
		cout<<"Alumno Nº"<<k<<endl;
	}
}
int main(int argc, char** argv){
	if(argc!=2){
		cout<<"ERROR: Los argumentos no son válidos"<<endl;
		cout<<"USAGE: "<< argv[0] << " [file]"<<endl;
		return -1;
	}
	Alumno alumnos[10];
	string fichero=argv[1];
	int n=lee(fichero, alumnos);
	if(n==-1){
		cout<<"ERROR: Fichero no encontrado, se abrira uno nuevo"<<endl;
		n=0;
	}
	else{
		n--;
	}
	int opcion_menu=0;
	while(opcion_menu!=6){
		cout<<"Seleccione una opcion:"<<endl;
		cout<<"1. Agregar alumno"<<endl;
		cout<<"2. Imprimir datos alumno"<<endl;
		cout<<"3. Imprimir datos todos alumnos"<<endl;
		cout<<"4. Modificar alumno"<<endl;
		cout<<"5. Eliminar alumno"<<endl;
		cout<<"6. Salir"<<endl;
		
		cin>>opcion_menu;
		switch(opcion_menu){
		case 1:{
			if(n<10){
				cin.ignore();
				cout<<"Escriba el DNI"<<endl;
				getline(cin, alumnos[n].dni);	
				while(DNI(alumnos[n].dni)!=true){
					cout<<"Escribe de nuevo el DNI: "<<endl;
					getline(cin, alumnos[n].dni);
					cout<<DNI(alumnos[n].dni)<<endl;
				}
			cout<<"Escriba la edad"<<endl;
			cin>>alumnos[n].edad;
			cout<<"Escriba la nota"<<endl;
			cin>>alumnos[n].nota;
			n++;
			}
		}
			break;
		case 2:{
			if(n>0){
				int m=0;
				cout<<"¿De que alumno quieres saber los datos?"<<endl;	
				impalumno(n);
				cin>>m;
				cout<<"Alumno"<<m<<endl;
				m--;
				cout<<"DNI: "<<alumnos[m].dni<<endl;
				cout<<"Edad: "<<alumnos[m].edad<<endl;
				cout<<"Nota: "<<alumnos[m].nota<<endl;
			}
			else{
			cout<<"No hay ningun alumno"<<endl;
			}
		}
			break;
		case 3:{
			if(n>0){
				for(int i=0; i<n; i++){
					cout<<"Alumno"<<i+1<<endl;
					cout<<"DNI: "<<alumnos[i].dni<<endl;
					cout<<"Edad: "<<alumnos[i].edad<<endl;
					cout<<"Nota: "<<alumnos[i].nota<<endl;
				}
			}
			else{
			cout<<"No hay ningun alumno"<<endl;
			}
		}
			break;
		case 4:{
			if(n>0){
				int mod=0;
				cout<<"¿De quien quieres modificar los datos?"<<endl;
				impalumno(n);
				cin>>mod;
				mod--;
				cin.ignore();
				cout<<"Escriba el DNI"<<endl;
				getline(cin, alumnos[mod].dni);	
					while(DNI(alumnos[mod].dni)!=true){
						cout<<"Escribe de nuevo el DNI: "<<endl;
						getline(cin, alumnos[mod].dni);
						cout<<DNI(alumnos[mod].dni)<<endl;
					}
				cout<<"Escriba la edad"<<endl;
				cin>>alumnos[mod].edad;
				cout<<"Escriba la nota"<<endl;
				cin>>alumnos[mod].nota;
			}
			else{
			cout<<"No hay ningun alumno"<<endl;
			}
		}
			break;
		case 5:{
			if(n>0){
				int del=0;
				cout<<"¿Que alumno quieres eliminar?"<<endl;
				impalumno(n);
				cin>>del;
				del--;
				for(int j=0; j<n; j++){
				alumnos[del+j]=alumnos[del+j+1];
				}
				n--;
			}
			else{
			cout<<"No hay ningun alumno"<<endl;
			}
		}
			break;
		}
	}
	if(!guarda(fichero, alumnos, 10)){
		cout<<"ERROR: No se pudo guardar el archivo"<<endl;
	}
	return 0;
}