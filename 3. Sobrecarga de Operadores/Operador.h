#include <iostream>

Operador::Operador(const Operador &p)
{
    *this=p;
}
Operador& Operador::operator ^ (const Operador &p)
{
    this->a ^ p.a;
    this->b ^ p.b;
    return *this;
} 