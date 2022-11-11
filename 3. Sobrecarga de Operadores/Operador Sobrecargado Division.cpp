#include <iostream>
#include <math.h>
#include "Operador.cpp"
#include "Operador.h"

using namespace std;

int main(int argc, char** argv) {
	float a,b,c;

    cout<<"Ingrese primer numero: ";
    cin>>a;
    cout<<"Ingrese segundo numero: ";
    cin>>b;
    c=a/b;
    cout<<"La division es: "<<c<<endl;
}