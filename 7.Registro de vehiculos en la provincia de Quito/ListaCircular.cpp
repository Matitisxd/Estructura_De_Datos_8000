/**
 * @file ListaCircular.cpp
 * @authors Granda Carlos, Rodriguez Mathyws 
 * @brief Funciones de la ListaCircular
 * @version 1.0
 * @date 2022-11-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "ListaCircular.hpp"
#include <string>
using namespace std;
//inicializacion
int validarCadenas(char cadena[50]);
int validarNum(char numero[10]);
bool isNumeric(std::string const &str);
int sw=0,validandoL;
void fechafinal(char fecha[], char dia[], char mes[], char anio[]);

ListaCircular::ListaCircular(){
    raiz = NULL; //raiz es nuestro primer espacio vacio
}

void fechafinal(char fecha[], char dia[], char mes[], char anio[]){
	char cero[]="0";
	char l[]="/";
	if(atoi(dia)<10){
    	if(atoi(mes)<10){
    		strcpy(fecha,cero);
    		strcat(fecha, dia);
			strcat(fecha, l);
			strcat(fecha,cero);
			strcat(fecha,mes);
			strcat(fecha, l);
			strcat(fecha,anio);
		}
		else{
			strcpy(fecha,cero);
    		strcat(fecha, dia);
			strcat(fecha, l);
			strcat(fecha,mes);
			strcat(fecha, l);
			strcat(fecha,anio);
		}
	}
	else{
		if(atoi(mes)<10){
    		strcpy(fecha, dia);
			strcat(fecha, l);
			strcat(fecha,cero);
			strcat(fecha,mes);
			strcat(fecha, l);
			strcat(fecha,anio);
		}
		else{
			strcpy(fecha, dia);
			strcat(fecha, l);
			strcat(fecha,mes);
			strcat(fecha, l);
			strcat(fecha,anio);
		}
	}
}

void ListaCircular::agregar(){
    Vehiculo *nuevo;
    
    nuevo = new Vehiculo();
    if(nuevo==NULL){
        cout<<"\n\t\t\tNO HAY MEMORIA SUFICIENTE"<<endl;
		return;
	}

    cout<<"\n\t\t\t|Registro del Vehiculo|"<<endl;
	cout<<endl;

    do{
        cin.clear();		
        fflush(stdin); //Ambos refrescan memoria
        cout<<"\t\t|Ingrese la Marca del Vehiculo: ";
        cin.getline(nuevo->marca,12);
        validandoL=validarCadenas(nuevo->marca);//Valida que solo sea letras
	}while(validandoL!=0);
	
    cin.clear();
    fflush(stdin);
    cout<<"\t\t|Ingrese la Placa del Vehiculo: ";
    cin.getline(nuevo->placaVehicular,8);
    fflush(stdin);
    
    do{
        cin.clear();
        fflush(stdin);
        cout<<"\t\t|Ingrese el Nombre de su Propietario: ";
        cin.getline(nuevo->nombrePropietario,40);
        validandoL=validarCadenas(nuevo->nombrePropietario);
	}while(validandoL!=0);
	
	char dia[3]; // 12 ocupa 2 espacios, puse 3 espacios para que no se solape la memoria
	bool diaC=true;
	char mes[3];
	bool mesC=true; //2014 ocupa 4 espacios, puse 5 espacios para que no se solape
	char anio[5];
	bool anioC=true;
	cin.clear();
    fflush(stdin);
    do{
    	
    	cout<<"\t\t|Ingrese el Anio de Revision: ";
    	cin>>anio;
    	if(isNumeric(anio)){
    		if(atoi(anio)>2000 && atoi(anio)<2023){
    			anioC=false;
			}
		}
    	
    }while(anioC);
    do{
    	
    	cout<<"\t\t|Ingrese el Mes de Revision: ";
    	cin>>mes;
    	if(isNumeric(mes)){
    		if(atoi(mes)<=12){
    			mesC=false;
			}
		}
    	
    }while(mesC);
    do{
    	
    	cout<<"\t\t|Ingrese el Dia de Revision: ";
    	cin>>dia;
    	if(isNumeric(dia)){
    		if(atoi(mes)==2){
    			if(atoi(dia)<=28) diaC=false;
			}
			else{
				if(atoi(dia)<=31) diaC=false;
			}
		}
    	
    }while(diaC);
    char fecha[11];
	fechafinal(fecha,dia, mes, anio);
	strcpy(nuevo->fecha,fecha);
    fflush(stdin);
	
	Vehiculo *aux = raiz;
	string nuevaPlaca;
	string nuevoNombre;
	string nuevaMarca;
	string raizPlaca;
	if(aux!=NULL){
		do{
			nuevaPlaca=nuevo->placaVehicular;
			nuevoNombre=nuevo->nombrePropietario;
			nuevaMarca=nuevo->marca;
			raizPlaca=aux->placaVehicular;
			if(nuevaPlaca == raizPlaca){
				cout <<"\nERROR: La placa ya esta existente."<<endl;
				system("pause");
				return;
			}
			if(nuevaPlaca.size()==0 || nuevoNombre.size()==0 || nuevaMarca.size()==0){
				cout <<"\nERROR: Un elemento ingresado esta vacio."<<endl;
				system("pause");
				return;
			}
			aux=aux->siguiente;
		}while(aux!=raiz);
	}
	if(raiz==NULL){
		nuevo->siguiente=nuevo;
		nuevo->anterior=nuevo;
		raiz=nuevo; //con esto se agrega el nodo
	}else{
		nuevo->siguiente=raiz;
		nuevo->anterior=raiz->anterior;
		raiz->anterior->siguiente=nuevo;
		raiz->anterior=nuevo;		
	}
	cout<<"\n\t\tRegistro de Vehiculo exitoso!"<<endl;
	system("pause");
	
	Vehiculo *copia = raiz;


	return;
}

bool ListaCircular::vacia(){
    if (raiz == NULL)
        return true;
    else
        return false;
}

void ListaCircular::consultarPrimero(){
	
	Vehiculo *copia = raiz;
    if ( copia == NULL ) {
		cout << "\n\t\tNo hay registros disponibles" << endl;
		system("pause");
		return;
	}

	cout << "\t\t\t|      Registros         |" << endl;

	do {
        cout<<endl;	
        cout<<"\t\t--------------------------------------------"<<endl;
        cout<<"\t\tMarca: "<<copia->marca<<endl;
        cout<<"\t\tPlaca Vehicular: "<<copia->placaVehicular<<endl;
        cout<<"\t\tFecha de Revision: "<<copia->fecha <<endl;
        cout<<"\t\tPropietario: "<<copia->nombrePropietario<<endl;
        cout<<endl;
        copia=copia->siguiente;
	} while( copia != raiz);
	system("pause");
    return;
}


void ListaCircular::borrar(){
    Vehiculo *eliminar = raiz;
    char resp;
    if ( eliminar == NULL ) {
		cout << "\n\t\tNo hay un registro existente" << endl;
		system("pause");
		return;
	}

    if ( raiz == raiz->siguiente) {
	cout << "\t\t\t|   Eliminacion de vehiculo   |" << endl;

	cout<<"\n\n";	
	
	cout<<"\t\t|Marca: "<<eliminar->marca<<endl;
	cout<<"\t\t|Placa Vehicular: "<<eliminar->placaVehicular<<endl;
	cout<<"\t\t|Fecha de Revision: "<<eliminar->fecha<<endl;
	cout<<"\t\t|Propietario: "<<eliminar->nombrePropietario<<endl;
    cout<<"\t\t------------------------------" << endl;
    const char *subtitulo[]={"------------------------------","|  Seguro que desea eliminar?  |","------------------------------"};
	    const char *subopciones[]={"\tSi","\tNo","------------------------------"};
	   	int o=2;
	   	int p=3;
	   	int op;
	   	system("pause");
	   	op=menuInteractivo(subtitulo,subopciones,o,p);
	   	switch(op){
	   		case 1:
	   			raiz=NULL;
      	 		free(eliminar);
      	 		cout <<"\n\t\tRegistro eliminado..." << endl;
      	 		system("pause");
	   			break;
	   		case 2:
	   			return;
    			break;
		}
	  return;
	}

	do
	{
		cout << "\t\t\t|   Eliminacion de registro   |" << endl;
		cout<<"\n\n";	
		
		cout<<"\t\t|Marca: "<<eliminar->marca<<endl;
		cout<<"\t\t|Placa Vehicular: "<<eliminar->placaVehicular<<endl;
		cout<<"\t\t|Fecha de Revision: "<<eliminar->fecha<<endl;
		cout<<"\t\t|Propietario: "<<eliminar->nombrePropietario<<endl;
		cout<<"\t\t------------------------------" << endl;
		const char *subtitulo[]={"------------------------------","|  Seguro que desea eliminar?  |","------------------------------"};
	    const char *subopciones[]={"\tSi","\tNo","------------------------------"};
	   	int o=2;
	   	int p=3;
	   	int op;
	   	system("pause");
	   	op=menuInteractivo(subtitulo,subopciones,o,p);
	   	switch(op){
	   		case 1:
	   			while ( raiz->siguiente != eliminar ) {		 
             	    raiz=raiz->siguiente;
       			    }
       			    raiz->siguiente = raiz->siguiente->siguiente;
        			raiz->siguiente->siguiente->anterior = raiz;
        		    free(eliminar);
         			cout <<"\t\tREGISTRO ELIMINADO" << endl;
        			return;	
	   			break;
	   		case 2:
    			break;
		}
	  eliminar=eliminar->siguiente;			
	} while (raiz != eliminar);
	cout << "\t\tSe mostraron todos los registros..." << endl;
	return;	
}

void ListaCircular::buscar(){
    Vehiculo *copia = raiz;
    int opcionBuscar;
    if(copia==NULL){
        cout<<"\n\t\t No hay registros disponibles"<<endl;
        system("pause");
		return;
	}
	bool regresar = true;
	const char *titulo[]={"----------------------------","|   Busqueda de Vehiculos   |","----------------------------"};
	const char *opciones[]={"\tPor su marca","\tPor placa vehicular","\tPor fecha de revision","\tPor propietario","Regresar al menu principal","-----------------------------"};
	int n=5;
	int m=3;
	char dia[3];
	bool diaC=true;
	char mes[3];
	bool mesC=true;
	char anio[5];
	bool anioC=true;
	char temp;
	do{
		bool menuBuscar=true;
		opcionBuscar=menuInteractivo(titulo,opciones,n,m);
    	switch(opcionBuscar){
			case 1:	
				char marca[12];
				char resp;
				do{
					cout << "\t\t\t|        Registro         |" << endl;
					cout<<"\t\tMarca: ";
					fflush(stdin);
					cin.getline(marca,12);
					fflush(stdin);
						do{	
                	    	if(strcmp(copia->marca, marca) == 0){
                            	cout<<endl;
                            	cout<<"\t\t|Marca: "<< copia->marca<<endl;
						    	cout<<"\t\t|Placa Vehicular: "<< copia->placaVehicular<<endl;
						    	cout<<"\t\t|Fecha de Revision: "<<copia->fecha<<endl;
						    	cout<<"\t\t|Propietario: "<< copia->nombrePropietario<<endl;
							}
							cout<<"\t\t--------------------------------" << endl;
    						copia=copia->siguiente;
	    		    	}while(copia!=raiz);
	    		    	const char *subtitulo[]={"----------------------------","|  Desea buscar otra marca?  |","----------------------------"};
	    		    	const char *subopciones[]={"\tSi","\tNo","----------------------------"};
	    		    	int o=2;
	    		    	int p=3;
	    		    	int op;
	    		    	system("pause");
	    		    	op=menuInteractivo(subtitulo,subopciones,o,p);
	    		    	switch(op){
	    		    		case 1:
	    		    			break;
	    		    		case 2:
	    		    			menuBuscar=false;
	    		    			break;
						}
				}while(menuBuscar);
				break;

			case 2:	
				char placaVehicular[10];
				do{
					cout << "\t\t\t|        Registro         |" << endl;
					cout<<"\t\tPlaca vehicular: ";
					fflush(stdin);
					cin.getline(placaVehicular,10);
					fflush(stdin);
					do{	
                    	if(strcmp(copia->placaVehicular,placaVehicular)==0){
                        	cout<<endl;
                        	cout<<"\t\t|Marca: "<<copia->marca<<endl;
					    	cout<<"\t\t|Placa Vehicular: "<<copia->placaVehicular<<endl;
					    	cout<<"\t\t|Fecha de Revision: "<<copia->fecha<<endl;
							cout<<"\t\t|Propietario: "<<copia->nombrePropietario<<endl;
						}
						cout<<"\t\t +++++++++++++++++++++++++++++++++++++" << endl;
    					copia=copia->siguiente;
	    			}while(copia!=raiz);
					const char *subtitulo[]={"----------------------------","|  Desea buscar otra placa?  |","----------------------------"};
	    		    const char *subopciones[]={"\tSi","\tNo","----------------------------"};
	    		    int o=2;
	    		    int p=3;
	    		    int op;
	    		    system("pause");
	    		    op=menuInteractivo(subtitulo,subopciones,o,p);
	    		    switch(op){
	    		    	case 1:
	    		    		break;
	    		    	case 2:
	    		    		menuBuscar=false;
	    		    		break;
					}
				}while(menuBuscar);
				break;	
			case 3:	
				cin.clear();
			    fflush(stdin);
    
				do{
					cout << "\t\t\t|        Registro         |" << endl;
					fflush(stdin);
					do{
    	
				    	cout<<"\t\t|Ingrese el Anio de Revision: ";
				    	cin>>anio;
				    	if(isNumeric(anio)){
				    		if(atoi(anio)>2000 && atoi(anio)<2023){
				    			anioC=false;
							}
						}
				    	
				    }while(anioC);
				    do{
				    	
				    	cout<<"\t\t|Ingrese el Mes de Revision: ";
				    	cin>>mes;
				    	if(isNumeric(mes)){
				    		if(atoi(mes)<=12){
				    			mesC=false;
							}
						}
				    	
				    }while(mesC);
				    do{
				    	
				    	cout<<"\t\t|Ingrese el Dia de Revision: ";
				    	cin>>dia;
				    	if(isNumeric(dia)){
				    		if(atoi(mes)==2){
				    			if(atoi(dia)<=28) diaC=false;
							}
							else{
								if(atoi(dia)<=31) diaC=false;
							}
						}
				    	
				    }while(diaC);
				    char fecha[11];
					fechafinal(fecha,dia, mes, anio);
						
					do{	
                    	if(strcmp(copia->fecha,fecha)==0){
                        	cout<<endl;
                        	cout<<"\t\t|Marca: "<<copia->marca<<endl;
					    	cout<<"\t\t|Placa Vehicular: "<<copia->placaVehicular<<endl;
					    	cout<<"\t\t|Fecha de Revision: "<<copia->fecha<<endl;
							cout<<"\t\t|Propietario: "<<copia->nombrePropietario<<endl;
						}
						cout<<"\t\t+++++++++++++++++++++++++++++++" << endl;
    					copia=copia->siguiente;
	    			}while(copia!=raiz);
					const char *subtitulo[]={"-------------------------------","|  Desea buscar otra fecha?  |","-------------------------------"};
	    		    const char *subopciones[]={"\tSi","\tNo","-------------------------------"};
	    		    int o=2;
	    		    int p=3;
	    		    int op;
	    		    system("pause");
	    		    op=menuInteractivo(subtitulo,subopciones,o,p);
	    		    switch(op){
	    		    	case 1:
	    		    		break;
	    		    	case 2:
	    		    		menuBuscar=false;
	    		    		break;
					}
				}while(menuBuscar);
				break;
			
			case 4:
				char nombrePropietario[40];
				do{

					cout << "\t\t\t|        Registro         |" << endl;
					cout<<"\t\tPropietario: ";
					fflush(stdin);
					cin.getline(nombrePropietario,40);
					fflush(stdin);
					do{	
                    	if(strcmp(copia->nombrePropietario,nombrePropietario)==0){
                        	cout<<endl;
                        	cout<<"\t\t|Marca: "<<copia->marca<<endl;
					    	cout<<"\t\t|Placa Vehicular: "<<copia->placaVehicular<<endl;
					    	cout<<"\t\t|Fecha de Revision: "<<copia->fecha<<endl;
							cout<<"\t\t|Propietario: "<<copia->nombrePropietario<<endl;
						}
						cout<<"\t\t++++++++++++++++++++++++++++++++++" << endl;
    					copia=copia->siguiente;
	    			}while(copia!=raiz);
					const char *subtitulo[]={"-------------------------------","|  Desea buscar otro nombre?  |","-------------------------------"};
	    		    const char *subopciones[]={"\tSi","\tNo","-------------------------------"};
	    		    int o=2;
	    		    int p=3;
	    		    int op;
	    		    system("pause");
	    		    op=menuInteractivo(subtitulo,subopciones,o,p);
	    		    switch(op){
	    		    	case 1:
	    		    		break;
	    		    	case 2:
	    		    		menuBuscar=false;
	    		    		break;
					}
				}while(menuBuscar);
				break;
			case 5:
				regresar = false;
				break;	
			}
	}while(regresar);
	return;
}

int validarCadenas(char cadena[50]){
	int i=0, validandoL=0, j;
	j=strlen(cadena); //se asigna el numero de caracteres que tiene la cadena a J
	
	while(i<j&&validandoL==0){
	
		if(isalpha(cadena[i])!=0||cadena[i]==32) // 32 para que acepte espacios tambien 
		{
			i++; //si es una letra avanza de lo contrario entra al else para salirse del ciclo
		}else{
			validandoL=1;
		}	
	}	
 return validandoL;
}

bool isNumeric(std::string const &str)
{
    auto it = str.begin();
    while (it != str.end() && std::isdigit(*it)) {
        it++;
    }
    return !str.empty() && it == str.end();
}