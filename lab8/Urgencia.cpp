//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#include "Urgencia.h"
#include <iostream>

using namespace std;

Urgencia::Urgencia()
{
    porcSeguro = 0;
    porcUrgencia = 0;
}

Urgencia::Urgencia(const Urgencia& rhs):
Paciente(rhs)
{
    porcUrgencia = rhs.porcUrgencia;
    porcSeguro = rhs.porcSeguro;
}

Urgencia::~Urgencia() = default;

double Urgencia::getPorcSeguro() const
{
    return porcSeguro;
}

void Urgencia::setPorcSeguro(double porc_seguro)
{
    porcSeguro = porc_seguro;
}

double Urgencia::getPorcUrgencia() const
{
    return porcUrgencia;
}

void Urgencia::setPorcUrgencia(double porc_urgencia)
{
    porcUrgencia = porc_urgencia;
}

std::ostream& operator<<(std::ostream& os, const Urgencia& rhs)
{
    char str[200];
    rhs.getNombre(str);
    os << rhs.getDni() << " " << str << endl;
    return os;
}
