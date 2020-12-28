//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#include "Paciente.hpp"
#include <cstring>

Paciente::Paciente()
{
    dni = 0;
    nombre = nullptr;
    codMed = nullptr;
}

Paciente::Paciente(const Paciente &rhs):
Paciente()
{
    *this = rhs;
}

Paciente& Paciente::operator=(const Paciente& rhs)
{
    if (this != &rhs) {
        setNombre(rhs.nombre);
        setCodMed(rhs.codMed);
        dni = rhs.dni;
    }
    return *this;
}

Paciente::~Paciente()
{
    delete[] nombre;
    delete[] codMed;
}

void Paciente::setNombre(const char *val)
{
    copystr(nombre, val);
}

void Paciente::setCodMed(const char *val)
{
    copystr(codMed, val);
}

void Paciente::setDni(int val)
{
    dni = val;
}

void Paciente::getNombre(char *ptr) const
{
    strcpy(ptr, nombre);
}

void Paciente::getCodMed(char *ptr) const
{
    strcpy(ptr, codMed);
}

int Paciente::getDni() const
{
    return dni;
}

void Paciente::copystr(char *&dest, const char *src)
{
    delete[] dest;
    dest = new char[strlen(src)+1];
    strcpy(dest, src);
}

bool Paciente::isNull()
{
    return nombre == nullptr && codMed ==nullptr;
}
