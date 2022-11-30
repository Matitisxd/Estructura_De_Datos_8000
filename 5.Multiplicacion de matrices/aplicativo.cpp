#include "Matrices.cpp" 

int main(){
	
	Matrices<int> matriz;
	
	char datoEntero1[30],datoEntero2[30],datoExponente[30] , *datoReal;
	int valorEntero1=0, valorEntero2=0,potencia=0;
	double valorReal=0.d;
	
	strcpy(datoEntero1,ingresarDatosEnteros("Escriba el numero de filas para A: "));
	valorEntero1=atoi(datoEntero1);
	matriz.setFa(valorEntero1);
	
	strcpy(datoEntero2,ingresarDatosEnteros("\nEscriba el numero de columnas para A: "));
	valorEntero2=atoi(datoEntero2);
	matriz.setCa(valorEntero2);
	
	strcpy(potencia,ingresarDatosEnteros("\nEscriba el numero de exponente: "));
	potencia=atoi(datoExponente);
	matriz.setCa(potencia);
	
	matriz.encerarMatriz();
	
	
	if(matriz.getCa()==matriz.getFb()){	
	
		int i,j,k;
		matriz.llenarMatrizA();
		matriz.potencia();
		
		//Realizamos el calculo
	
	//	matriz.multiplicacionMatrices(matriz.getMat1(),matriz.getMat2(),matriz.getMatR());
		matriz.multiplicacionRecursivaMatrizA(matriz.getMat1(),getpotencia(),matriz.getMatR(),i);
		cout<<endl;                                                            
		//imprimimos la matriz resultante
		
		matriz.imprimirMatriz(matriz.getMatR(),"R");
		free(matriz.getMat1());
		free(matriz.getpotencia())
		free(matriz.getMatR());
	}else{
	cout<<"\nLa multiplicacion entre estas dimensiones de matrices no se pueden realizar"<<endl;
	}
	return 0;
}