#include <iostream>

class Interfaz{
	public:
		virtual ~Interfaz
		virtual char= Ingreso_datos (char const *msj)=0;
		virtual char= Ingresar_enteros(char const *msj)=0;
		virtual char= Ingresar_datos_reales(char const *msj)=0;
		virtual float Ingresar_datos_reales()=0;
		virtual int Ingresar_datos_enteros()=0;
};