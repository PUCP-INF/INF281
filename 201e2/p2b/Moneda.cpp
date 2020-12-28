//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#include "Moneda.h"
#include <cstring>

Moneda::Moneda()
{
    simbolo = 0;
    equivalencia = 0;
    nombre = nullptr;
}
Moneda::Moneda(const Moneda& rhs)
{
    simbolo = rhs.simbolo;
    equivalencia = rhs.equivalencia;
    nombre = nullptr;
    setNombre(rhs.nombre);
}
Moneda::~Moneda()
{
    delete nombre;
}
char Moneda::getSimbolo() const
{
    return simbolo;
}
double Moneda::getEquivalencia() const
{
    return equivalencia;
}
void Moneda::getNombre(char* ptr) const
{
    strcpy(ptr, nombre);
}
void Moneda::setSimbolo(char val)
{
    simbolo = val;
}
void Moneda::setEquivalencia(double val)
{
    equivalencia = val;
}
void Moneda::setNombre(const char* val)
{
    delete nombre;
    nombre = new char[strlen(val)+1];
    strcpy(nombre, val);
}
void Moneda::leer(std::ifstream& in)
{
    char _, str[50];
    in >> simbolo >> _ >> equivalencia >> _;
    in.getline(str, 50);
    setNombre(str);
}
void Moneda::imprimir(std::ofstream& out)
{

}
