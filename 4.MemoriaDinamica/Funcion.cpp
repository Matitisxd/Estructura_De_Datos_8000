#include<iostream>
#include "funcion.h"

template<typename T>
funcion<T>::funcion(int t){
	this->t=t;
	this->ptr = (T*)calloc(t, sizeof(T*));
}

template<typename T>
funcion<T>::funcion(){
}

template<typename T>
void funcion<T>::setT (T otroT){
		t=otroT;
}

template<typename T>
void funcion<T>::setPtr (T* otroPtr){
		ptr=otroPtr; 
	}

template<typename T>	
	T funcion<T>:: getT (){
		return t;
	}

template<typename T>
	T*funcion<T>::  getPtr(){
		return *ptr; //preguntar si aqui va el puntero como retorno
	}

template<typename T>
void funcion <T> ::ingresar(T *p,T t){ //saca plantilla
    //int i=0; //inicializa variable iterativa
    for(int i=0;i<t;i++) //for estructural
    {
        printf("\nIngrese el valor: "); //pide el valor al usuario
        scanf("%d",*(&p)+i); //agarra el valor
    }
}

template<typename T>
void funcion <T> ::imprimir(T *p,T t){
    //int i=0; //inicializa variable iterativa
    for(int i=0;i<t;i++) //for estructural
    {
        printf("\n\nValores ingresados: "); //pide valores a ingrear
        printf("%d",*(&(*p))); //Que significa esto preguntar al profe procesa variables a ingresar
        printf("\n"); 
        *(p++);//navega por la direccion del puntero extrayendo los valores
    }
}

template<typename T>
void funcion <T> ::procesar(T *p,T t){
    int e=0; //inicializando variable de e
    printf("\nIngrese el escalar:"); //pide al escalar para multiplicar
    scanf("%d",&e); //se ingresa y escanea el escalar

    for(int i=0;i<t;i++)  //for estructural
    {
        *p=(*(&(*p)))*e; //multiplica el valor ptr con el escalar
        *(p++); //navega por la direccion del puntero extrayendo los valores
    }
}