#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include"Funcion.cpp"


using namespace std;


int main(){
	
    int tam=0; //incializo variable tam
   // int *ptr=new int[10];
   //if(*ptr=realloc(*ptr,sizeof(int))    
    int *ptr=(int*)malloc(4*sizeof(int)); //inicializo el puntero con malloc
	
    cout<<"\nIngrese el tamano: "; //Pedimos al usuario que ingrese el tamaño
    cin>>tam; //se extrae el tamaño o valor ingresado
    funcion<int> val; //Instanciamos el objeto 
    val.ingresar(ptr,tam); //invocamos al metodo ingresar
    val.imprimir(ptr,tam);
    val.procesar(ptr,tam);
    val.imprimir(ptr,tam);   
    getch();
}