//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#include "Paciente.h"
#include "Ambulatorio.h"
#include "Emergencia.h"
#include "Urgencia.h"
#include <cstring>

Paciente::Paciente():
dni(0),
nombre(nullptr),
codMed(nullptr)
{}

Paciente::Paciente(const Paciente &orig):
dni(orig.getDni()),
nombre(nullptr),
codMed(nullptr)
{
    char buff[200];
    orig.getNombre(buff);
    setNombre(buff);
    orig.getCodMed(buff);
    setCodMed(buff);
}

Paciente::~Paciente()
{
    delete nombre;
    delete codMed;
}

int Paciente::getDni() const
{
    return dni;
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

void Paciente::setNombre(const char *val)
{
    copystr(nombre, val);
}

void Paciente::setCodMed(const char *val)
{
    copystr(codMed, val);
}

void Paciente::readInfo(std::istream &is)
{
    char buff[200], _;
    is >> dni >> _;
    is.getline(buff, 200, ',');
    setNombre(buff);
    is.getline(buff, 200, ',');
    setCodMed(buff);
}

void Paciente::copystr(char *&dest, const char *src)
{
    delete dest;
    dest = new char[strlen(src)+1];
    strcpy(dest, src);
}

std::istream &operator>>(std::istream &is, Paciente *&pac) {
    char tipo, _;
    is >> tipo >> _;
    if (tipo == 'E') {
        pac = new Emergencia;
    } else if (tipo == 'U') {
        pac = new Urgencia;
    } else if (tipo == 'A') {
        pac = new Ambulatorio;
    } else {
        return is;
    }
    pac->leer(is);
    return is;
}

std::ostream &operator<<(std::ostream &os, Paciente *&pac) {
    if (pac != nullptr) pac->imprimir(os);
    return os;
}
