//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#include "Ambulatorio.h"
#include <iostream>

using namespace std;

Ambulatorio::Ambulatorio():
Paciente()
{
    porcSeguro = 0;
}

Ambulatorio::Ambulatorio(const Ambulatorio &rhs):
Paciente(rhs)
{
    porcSeguro = rhs.porcSeguro;
}

Ambulatorio::~Ambulatorio() = default;

double Ambulatorio::getPorcSeguro() const
{
    return porcSeguro;
}

void Ambulatorio::setPorcSeguro(double val)
{
    porcSeguro = val;
}

std::ostream& operator<<(std::ostream& os, const Ambulatorio& rhs)
{
    char str[200];
    rhs.getNombre(str);
    os << rhs.getDni() << " " << str << endl;
    return os;
}
