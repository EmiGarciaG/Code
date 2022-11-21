//Fichero contador.cc
//Declaracion includes para bibliotecas y ficheros.h 
#include "contador.h"


//Funcion Valor(Comprueba que el valor del contador no supere ni sea menor de lo establecido)
void Contador::Valor(){
	if(valor_>max_){
		valor_=max_;
	}
	else if(valor_<min_){
		valor_=min_;
	}
}

Contador Contador::operator=(const int &valor){
	operaciones.push_back(valor_);
	valor_=valor;
	Valor();
	return this->valor_;
}

Contador Contador::operator=(const Contador &c){
	operaciones.push_back(valor_);
	valor_=c.valor_; 
	min_=c.min_; 
	max_=c.max_;
	return this->valor_;
}

Contador Contador::operator++(void){
	operaciones.push_back(valor_);
	valor_++;
	Valor();
	return this->valor_;
}

Contador Contador::operator++(int){
	Contador aux=this->valor_;
	operaciones.push_back(valor_);
	valor_++;
	Valor();
	return aux;
}

Contador Contador::operator--(void){
	operaciones.push_back(valor_);
	valor_--;
	Valor();
	return this->valor_;
}

Contador Contador::operator--(int){
	Contador aux=this->valor_;
	operaciones.push_back(valor_);
	valor_--;
	Valor();
	return aux;
}

Contador Contador::operator+(const int &numero){
	Contador c(valor_, min_, max_);
	operaciones.push_back(valor_);
	c.valor_+=numero;
	c.Valor();
	return c;
}

Contador operator+(const int &numero, const Contador &c){
	Contador op(c);
	op.valor_+=numero;
	op.Valor();
	return op;
}

Contador Contador::operator-(const int &numero){
	Contador c(valor_, min_, max_);
	operaciones.push_back(valor_);
	c.valor_-=numero;
	c.Valor();
	return c;
}

Contador operator-(const int &numero, const Contador &c){
	Contador op(c);
	op.valor_=numero-op.valor_;
	op.Valor();
	return op;
}

//Funcion undo(Devuelve el valor guardado en la lista operaciones antes de utilizar los operadores)
bool Contador::undo(int n){
	if((n>(int)operaciones.size())|| n<1){ //Comprueba si es posible deshacer operaciones
		return false;
	}
	else{
		for(int i=0; i<n; i++){		//Deshace tantas operaciones como se indique
			valor_=operaciones.back();	
			operaciones.pop_back();
		}
		return true;
	}
}
