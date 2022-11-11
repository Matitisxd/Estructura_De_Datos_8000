#include <iostream>

class Operador {

private:
    int a, b;

public:
	
    Operador() : a(0), b(0) {}
    Operador(const int a,const int b) {
	this->a = a;
	this->b = b;
    }
    Operador(const Operador&);
    
    Operador& operator ^ (const Operador &p);
    


};
