//Fichero contador.h
//Declaracion includes para bibliotecas y ficheros.h 
#ifndef CONTADOR_H
#define CONTADOR_H
#include <list>

//Declaracion clase Contador
class Contador{  
    private:        //Parte privada de la clase Contador
        int valor_, min_, max_;     //Variables tipo int valor_, min_, max_
        std::list <int> operaciones;    //Lista operaciones
        void Valor();   //Funcion tipo void que comprueba el valor
    public:         //Parte publica de la clase Contador
        Contador(int valor=0, int min=0, int max=1000){
            if(valor<min || valor>max || min>max){
                valor_=0;
                min_=0;
                max_=1000;
            }
            else{
                valor_=valor;
                min_=min;
                max_=max;
            }
        }//Constructor por defecto
        Contador operator=(const int &valor);   //Operador de asignación (=) con un valor
        Contador operator=(const Contador &c);  //Operador de asignación (=) con otro contador
        Contador operator++(void);  //Operador ++ para ++valor
        Contador operator++(int);   //Operador ++ para valor++
        Contador operator--(void);  //Operador -- para --valor
        Contador operator--(int);   //Operador -- para valor--
        Contador operator+(const int &numero);  //Operador + (c+numero)
        friend Contador operator+(const int &numero, const Contador &c);    //Operador + (numero+c)
        Contador operator-(const int &numero);  //Operador - (c-numero)
        friend Contador operator-(const int &numero, const Contador &c);    //Operador - (numero-c)
        bool undo(int n=1); //Función tipo bool que deshace las ultimas n operaciones
        inline int get() const {return valor_;} //Funcion tipo int que devuelve el valor 
};
//Fin declaracion del fichero contador.h
#endif

