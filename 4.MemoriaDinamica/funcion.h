#include<iostream>

template<typename T> //declaramos plantilla

/**
     * @brief Declarar metodos ingresar, procesar, imprimir
*/
class funcion{
    
    public:
    /**
     * @brief Pide el ingreso de datos
     * @param  T*,T
     * @return void
    */
    void ingresar(T*,T );
    /**
     * @brief Imprime los datos, muestra en pantalla de la consola
     * @param  T* ptr recibe un numero tipo puntero, T
     * @return void
    */
    void imprimir(T*, T);
    /**
     * @brief Multiplica el arreglo por el escalar ingresado (proceso y almacenamiento)
     * @param   T* ptr recibe un numero tipo puntero,T
     * @return void
    */
    void procesar(T*, T);
    /**
     * @brief Constructor default de la clase
     * @param  T t -> recibe el tamaño, T* ptr recibe un numero tipo puntero
     * @return funcion
    */
    funcion (int t);
    
    funcion ();
	
	void setT (T otroT);
	
	void setPtr (T* otroPtr);
	
	T getT ();
	
	T* getPtr();
	
    private:
        T*  ptr;
        T  t;
};