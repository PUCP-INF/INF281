//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#include "Ambulatorio.h"
#include <iomanip>

using namespace std;

Ambulatorio::Ambulatorio():
        porcSeguro(0),
        Paciente()
{}

Ambulatorio::Ambulatorio(const Ambulatorio &orig):
        porcSeguro(orig.getPorcSeguro()),
        Paciente(orig)
{}

double Ambulatorio::getPorcSeguro() const
{
    return porcSeguro;
}

void Ambulatorio::setPorcSeguro(double val)
{
    porcSeguro = val;
}

Ambulatorio::~Ambulatorio() = default;

void Ambulatorio::leer(std::istream &is)
{
    char _;
    readInfo(is);
    is >> porcSeguro >> _;
    if (_ != ',') is.unget();
}

void Ambulatorio::imprimir(std::ostream &os)
{
    char buff[200];
    os << getDni() << "    ";
    getNombre(buff);
    os << setw(40) << left << buff << getEdad() << "      ";
    os << left << setw(30);
    if (observacion()==1) {
        os << "Persona de Riesgo";
    } else if (observacion() == 2){
        os << "Debe venir con su apoderado";
    }
    os << endl;
}

int Ambulatorio::observacion() const
{
    if (getEdad()>65) return 1;
    if (getEdad()<18) return 2;
    return 3;
}

int Ambulatorio::prioridad() const
{
    return 1;
}
