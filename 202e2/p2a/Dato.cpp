//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#include "Dato.h"

Dato::Dato(int prioridad, int valor):
prioridad(prioridad),
valor(valor)
{}

void Dato::setPrioridad(int val)
{
    prioridad = val;
}
void Dato::setValor(int val)
{
    valor = val;
}
int Dato::getPrioridad() const
{
    return prioridad;
}
int Dato::getValor() const
{
    return valor;
}
int Dato::operator-(const Dato& rhs) const
{
    return prioridad - rhs.prioridad;
}
std::ostream& operator<<(std::ostream& os, const Dato& rhs)
{
    os << rhs.getPrioridad() << " " << rhs.getValor() << std::endl;
    return os;
}
