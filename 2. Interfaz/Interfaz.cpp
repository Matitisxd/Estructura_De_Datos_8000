#include "Interfaz.h"

char *Ingreso_datos(char const *msj){
	char *dato= new char[10];
	char c;
	int i=0;
	printf("%s\n",msj);
	while((c=getch())!=13){
		if(c>='0'&& c<='9'){
			printf("%c",c);
			dato[i++]=c;
		}
	}
	dato[i]='0';
	return dato;
}

char *Ingreso_datos_reales(char const *msj){
	char *dato=new char [10],c;
	int i=0;
	punto=0;
	printf("%s",msj);
	while((c=getch())!=13){
		if(c>='0'&&c<='9'){
			printf("%c",c);
			dato[i++]=c;
		}
		else if(c=='8'&&c=='127'){
			printf("\b");
			dato[i--]=0;
			i--;
		}else if(c=='.'&& punto==0){
			printf("%c",c);
			dato[i++]=c;
			punto --;
		}
	}dato[i]='\0';
	return (dato);
}

float ingres_datos_reales(){
	char *dato=new char[10],c;
	int i=0
	punto=0;
	printf("Ingrese la opcion: ");
	while((c=getch())!=13){
		if(c>='0'&&c<='9'){
			printf("%c",c);
			dato[i++]=c;
		}
		else if(c=='8'&&c=='127'){
			printf("\b");
			dato[i--]=0;
		}else if(c=='.'&& punto==0){
			printf("%c",c);
			dato[i++]=c;
			punto --;
		}
	}dato[i]='\0';
	return (dato);
}