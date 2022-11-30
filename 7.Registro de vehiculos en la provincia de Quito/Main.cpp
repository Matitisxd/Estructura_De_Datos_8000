/**
 * @file Main.cpp
 * @authors Granda Carlos, Rodriguez Mathyws 
 * @brief Archivo principal de nuestro programa
 * @version 0.3
 * @date 2022-11-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<stdlib.h>
#include "ListaCircular.cpp"

using namespace std;
void menu();

int main(){
		menu();
	
	return 0;
}

void menu(){
	const char *titulo[] = {"","||         AGENDA PARA REVISION VEHICULAR EN PICHINCHA        ||","","Menu de opciones:","----------------",""};
	const char *opciones[]={"\tREGISTRE SU VEHICULO","\tCONSULTE UN VEHICULO","\tBUSCAR UN VEHICULO","\tBORRAR UN VEHICULO","\tSALIR DEL PROGRAMA",""};
	int n = 5; // Numero de opciones
	int m = 6; //Numero de lineas de titulo
	int opcion; 
    ListaCircular lst;//llamado a la lista
	bool repite = true;	//se asigna a repite que sea verdadera				
	do{
		opcion=menuInteractivo(titulo, opciones,n,m);
		switch(opcion){
			case 1:
				lst.agregar();
				break;
			case 2:
				lst.consultarPrimero();
				break;	
			case 3:
				lst.buscar();
				break;	
			case 4:
				lst.borrar();
				break;
			case 5:
				repite = false;// repite es falso
				cout<<"\n\t\tGracias por su visita xD"<<endl;
				break;
	    }
	}while(repite);//se repite hasta que repite sea falso o el usuario marque la opcion 5
}