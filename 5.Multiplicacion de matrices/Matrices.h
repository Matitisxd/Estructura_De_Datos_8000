#include <iostream>
#include <stdlib.h>

using namespace std;

template <typename T>
class Matrices{
	public:
		void multiplicacionMatrices(T **, P**, T **);
		
		void encerarMatriz();
		
		void llenarMatrizRandom();
		
		void imprimirMatriz(T**,char*);
		
		Matrices();
		
		void pedirDatos();
		void llenarMatrizA();
		void potencia();
		void multiplicacionRecursivaMatrizA(T**,T**,T**,T);
		void potencia();
		void multiplicacionRecursiva(T**,T**,T**,T,T,T);
		
		//getters y setters de los atributos de la clase
		T** getMat1();
		T** potencia();
		T** getMatR();
		T getFa(); T getFb(); T getCa(); T getCb(); T getK();
		void setMat1(T** );
		void setpotencia(T** );
		void setMatR(T** );
		void setFa(T); void setFb(T); void setCa(T); void setCb(T); void setK(T);
		
	private:
		//atributos de la clase	
		T **mat1,**potencia,**matR,fa,ca,fb,cb,k,i,j;
};