//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#include "Emergencia.h"
#include <cstring>
#include <iomanip>

using namespace std;

Emergencia::Emergencia():
        telefonoRef(0),
        nombreRef(nullptr),
        Paciente()
{}

Emergencia::Emergencia(const Emergencia &orig):
        telefonoRef(orig.getTelefonoRef()),
        nombreRef(nullptr),
        Paciente(orig)
{
    char buff[200];
    orig.getNombreRef(buff);
    setNombreRef(buff);
}

Emergencia::~Emergencia()
{
    delete nombreRef;
}

int Emergencia::getTelefonoRef() const {
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

void Emergencia::leer(std::istream &is)
{
    char buff[200], _;
    readInfo(is);
    is.getline(buff, 200, ',');
    setNombreRef(buff);
    is >> telefonoRef >> _;
    if (_ != ',') is.unget();
}

void Emergencia::imprimir(std::ostream &os)
{
    char buff[200];
    os << getDni() << "    ";
    getNombre(buff);
    os << setw(40) << left << buff << getEdad() << "      ";
    os << left << setw(30);
    if (observacion()==1) {
        os << "Persona de Riesgo";
    } else {
        os << "";
    }
    os << setw(25) << left << nombreRef << telefonoRef << endl;
}

int Emergencia::observacion() const
{
    if (getEdad() > 65) return 1;
    return 3;
}

int Emergencia::prioridad() const
{
    return 3;
}
