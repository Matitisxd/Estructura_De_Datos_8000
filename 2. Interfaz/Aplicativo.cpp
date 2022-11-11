#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "interfaz.cpp"

int main(int argc, char** argv){
	
	using namespace std; 
	
	Numero<int> entero;
	Numero<float> flotante;
	Numero<double> real;
	
	int num_entero=0;
	float num_flotante=0.f;
	double num_real=0;
	char dato_entero[20], dato_flotante[20], dato_real[20];
	
	strcpy(dato_flotante,Ingresar_datos_reales("\n"ingrese un numero entero: ));
	num_entero=atoi(dato_entero);
	entero.setNum(num_entero);
	
	strcpy(dato_flotante,Ingresar_datos_reales("\nIngrese un valor flotante: "));
	num_flotante=atof(dato_flotante);
	flotante.setNum(num_flotante);
	
	strcpy(dato_real,Ingresar_datos_reales("\nIngrese un valor real: "));
	num_real=atof(dato_real);
	real.setnum(num_real);
	
	cout<<"\n Numero de tipo int: "<<entero.getNum();
	cout<<"\n Numero de tipo float: "<<flotante.getNum<<endl;
	cout<<"Numero de tipo double: "<<real.getNum()<<endl;
	return 0;
}