//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#include "Emergencia.h"
#include <cstring>
#include <iostream>

using namespace std;

Emergencia::Emergencia()
{
    telefonoRef = 0;
    nombreRef = nullptr;
}

Emergencia::Emergencia(const Emergencia& rhs):
Paciente(rhs),
nombreRef(nullptr),
telefonoRef(0)
{
    *this = rhs;
}

Emergencia::~Emergencia()
{
    delete nombreRef;
}

int Emergencia::getTelefonoRef() const
{
    return telefonoRef;
}
void Emergencia::setTelefonoRef(int val)
{
    telefonoRef = val;
}

void Emergencia::getNombreRef(char *ptr) const
{
    strcpy(ptr, nombreRef);
}

void Emergencia::setNombreRef(const char *val)
{
    copystr(nombreRef, val);
}

Emergencia& Emergencia::operator=(const Emergencia& rhs)
{
    if (this != &rhs) {
        Paciente::operator=(rhs);
        setNombreRef(rhs.nombreRef);
        telefonoRef = rhs.telefonoRef;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Emergencia& rhs)
{
    char str[200];
    rhs.getNombre(str);
    os << rhs.getDni() << " " << str << endl;
    return os;
}
