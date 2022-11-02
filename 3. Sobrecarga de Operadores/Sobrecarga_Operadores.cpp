#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
using namespace std;
class Pareja {

private:
    int a, b;

public:
    Pareja() : a(0), b(0) {}
    Pareja(const int a,const int b) {
	this->a = a;
	this->b = b;
    }

    Pareja(const Pareja&);

    Pareja& operator + (const Pareja &p);
    Pareja& operator - (const Pareja &p);
    Pareja& operator * (const Pareja &p);
    Pareja& operator / (const Pareja &p);
    Pareja& operator = (const Pareja &p);
    Pareja& operator ++();
    bool  operator ==(const Pareja &p) const;

    friend ostream& operator << (ostream &o,const Pareja &p);
    friend istream& operator >> (istream &o, Pareja &p);

    /**
     * @brief %
     * @param p 
     * @return Pareja
    */
    Pareja& operator % (const Pareja &p);

    /**
     * @brief <
     * @param p 
     * @return bool
    */
    bool operator < (const Pareja &p);

    /**
     * @brief >
     * @param p 
     * @return bool
    */
    bool operator > (const Pareja &p);

    /**
     * @brief <=
     * @param p 
     * @return bool
    */
    bool operator <= (const Pareja &p);

    /**
     * @brief >=
     * @param p 
     * @return bool
    */
    bool operator >= (const Pareja &p);

    /**
     * @brief +=
     * @param p 
     * @return Pareja
    */
    Pareja& operator += (const Pareja& p);

    /**
     * @brief -=
     * @param p 
     * @return Pareja
    */
    Pareja& operator -= (const Pareja& p);

    /**
     * @brief *=
     * @param p 
     * @return Pareja
    */
    Pareja& operator *= (const Pareja& p);

    /**
     * @brief /=
     * @param p 
     * @return Pareja
    */
    Pareja& operator /= (const Pareja& p);

    /**
     * @brief %=
     * @param p 
     * @return Pareja
    */
    Pareja& operator %= (const Pareja& p);
};

// implementacion de los operadores para la clase Pareja
//....................................
Pareja::Pareja(const Pareja &p)
{
    *this=p;
}
//....................................
Pareja& Pareja::operator + (const Pareja &p)
{
    this->a += p.a;
    this->b += p.b;
    return *this;
}
//....................................
Pareja& Pareja::operator - (const Pareja &p)
{
    this->a -= p.a;
    this->b -= p.b;
    return *this;
}
//....................................
Pareja& Pareja::operator * (const Pareja &p)
{
    this->a *= p.a;
    this->b *= p.b;
    return *this;
}
//....................................
Pareja& Pareja::operator / (const Pareja &p)
{
    if (p.a != 0) this->a /= p.a;
    if (p.b != 0) this->b /= p.b;
    return *this;
}
//....................................
Pareja& Pareja::operator = (const Pareja &p)
{
    if(this!=&p){ //Comprueba que no se esté intentanod igualar un objeto a sí mismo
        if (p.a != 0) this->a = p.a;
        if (p.b != 0) this->b = p.b;
    }
    return *this;
}

//....................................
Pareja& Pareja::operator ++ ()
{
    this->a ++;
    this->b ++;
    return *this;
}

//....................................
bool Pareja::operator == (const Pareja &p) const
{
    return this->a == p.a && this->b == p.b;
}

// implemetaci¢n de operadores no miembros
ostream& operator << (ostream &o,const Pareja &p)
{
    o << "(" << p.a << ", " << p.b << ")";
    return o;
}

istream& operator >> (istream &i, Pareja &p)
{
    cout << "Introducir valores para ( a, b) :";
    i >> p.a >> p.b;
    i.ignore();
    return i;
}


/**
 * @brief %
 * @param p 
 * @return Pareja
*/
Pareja& Pareja::operator % (const Pareja &p)
{
    if (p.a != 0) this->a %= p.a;
    if (p.b != 0) this->b %= p.b;
    return *this;
}

/**
 * @brief <
 * @param p 
 * @return bool
*/
bool Pareja::operator < (const Pareja &p)
{
    return this->a < p.a && this->b < p.b;
}


/**
 * @brief >
 * @param p 
 * @return bool
*/
bool Pareja::operator > (const Pareja &p)
{
    return this->a > p.a && this->b > p.b;
}

/**
 * @brief <=
 * @param p 
 * @return bool
*/
bool Pareja::operator <= (const Pareja &p)
{
    return this->a <= p.a && this->b <= p.b;
}

/**
 * @brief >=
 * @param p 
 * @return bool
*/
bool Pareja::operator >= (const Pareja &p)
{
    return this->a >= p.a && this->b >= p.b;
}

/**
 * @brief +=
 * @param p 
 * @return Pareja
*/
Pareja& Pareja::operator+=(const Pareja& p){
    this->a += p.a;
    this->b += p.b;
    return *this;
}

/**
 * @brief -=
 * @param p 
 * @return Pareja
*/
Pareja& Pareja::operator-=(const Pareja& p){
    this->a -= p.a;
    this->b -= p.b;
    return *this;
}

/**
 * @brief *=
 * @param p 
 * @return Pareja
*/
Pareja& Pareja::operator*=(const Pareja& p){
    this->a *= p.a;
    this->b *= p.b;
    return *this;
}

/**
 * @brief /=
 * @param p 
 * @return Pareja
*/
Pareja& Pareja::operator/=(const Pareja& p){
    this->a /= p.a;
    this->b /= p.b;
    return *this;
}

/**
 * @brief %=
 * @param p 
 * @return Pareja
*/
Pareja& Pareja::operator%=(const Pareja& p){
    this->a %= p.a;
    this->b %= p.b;
    return *this;
}


int main(int argc, char** argv) {
    Pareja A(150,  75);
    Pareja B(100, 15);
    Pareja C;
	cout << "A = " << A << "\n";
    cout << "B = " << B << "\n";
    cout << "........................." << endl;
    C = A + B;
    cout << "A = " << A << "\n";
    cout << "C = " << C << endl;
    cout << "........................." << endl;
	C = A - B;
    cout << "A = " << A << "\n";
    cout << "C = " << C << endl;
    cout << "........................." << endl;
 	C = A * B;
    cout << "A = " << A << "\n";
    cout << "C = " << C << endl;
    cout << "........................." << endl;
 	C = A / B;
    cout << "A = " << A << "\n";
    cout << "C = " << C << endl;
    cout << "........................." << endl;
    C = A / B;
    cout << "A = " << A << "\n";
    cout << "C = " << C << endl;
    cout << "........................." << endl;
    ++C;
    cout << "C = " << C << endl;
    cout << "A == B " << ( (A==B)?"  True \n": "  False  \n");
    cout << "........................." << endl;
    C = A = B = ++C;
    cout << "A = " << A << "\n";
    cout << "B = " << B << "\n";
    cout << "C = " << C << endl;
    cout << "........................." << endl;
    // PRIMER DIA
    cout << "A = " << A << "\n";
    cout << "B = " << B << "\n";
    C = A % B;
    cout << "A % B =" << C << endl;
    cout << "........................." << endl;

    //Segundo Dia (09/06/2020)
    cout << "A = " << A << "\n";
    cout << "B = " << B << "\n";
    cout << "C = " << C << endl;
    cout << "A < B " << ( (A<B)?"  True \n": "  False  \n");
    cout << "........................." << endl;

    //Tercer Dia (10/06/2020)
    cout << "A = " << A << "\n";
    cout << "B = " << B << "\n";
    cout << "C = " << C << endl;
    cout << "A < B " << ( (A>B)?"  True \n": "  False  \n");
    cout << "........................." << endl;

    //Cuarto Dia (11/06/2020)
    cout << "A = " << A << "\n";
    cout << "B = " << B << "\n";
    cout << "C = " << C << endl;
    cout << "A < B " << ( (A>=B)?"  True \n": "  False  \n");
    cout << "........................." << endl;

    //Quinto Dia (12/06/2020)
    cout << "A = " << A << "\n";
    cout << "B = " << B << "\n";
    cout << "C = " << C << endl;
    cout << "A < B " << ( (A<=B)?"  True \n": "  False  \n");
    cout << "........................." << endl;

    /**/
    cout << "A = " << A << "\n";
    cout << "C = " << C << "\n";
    C += A;
    cout << "C += A =" << C << endl;
    cout << "........................." << endl;
    cout << "B = " << B << "\n";
    cout << "C = " << C << "\n";
    C -= B;
    cout << "C -= B =" << C << endl;
    cout << "........................." << endl;
    cout << "A = " << A << "\n";
    cout << "B = " << B << "\n";
    A *= B;
    cout << "A *= B =" << A << endl;
    cout << "........................." << endl;
    cout << "B = " << B << "\n";
    cout << "B = " << B << "\n";
    B /= B;
    cout << "B /= B =" << B << endl;
    cout << "........................." << endl;
    cout << "B = " << B << "\n";
    cout << "B = " << C << "\n";
    B %= B;
    cout << "B %= B =" << B << endl;
    cout << "........................." << endl;

    return 0;
}
