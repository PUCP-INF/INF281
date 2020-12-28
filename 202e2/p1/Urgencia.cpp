//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#include "Urgencia.h"
#include <iomanip>

using namespace std;

Urgencia::Urgencia():
        porcUrgencia(0),
        porcSeguro(0)
{}

Urgencia::Urgencia(const Urgencia &orig):
        Paciente(orig),
        porcUrgencia(orig.getPorcUrgencia()),
        porcSeguro(orig.getPorcSeguro())
{}

Urgencia::~Urgencia() = default;

double Urgencia::getPorcSeguro() const
{
    return porcSeguro;
}

void Urgencia::setPorcSeguro(double val)
{
    porcSeguro = val;
}

double Urgencia::getPorcUrgencia() const
{
    return porcUrgencia;
}

void Urgencia::setPorcUrgencia(double val)
{
    porcUrgencia = val;
}

void Urgencia::leer(std::istream &is)
{
    char _;
    readInfo(is);
    is >> porcSeguro >> _ >> porcUrgencia >> _;
    if (_ != ',') is.unget();
}

void Urgencia::imprimir(std::ostream &os)
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

int Urgencia::observacion() const
{
    if (getEdad()>65) return 1;
    if (getEdad()<18) return 2;
    return 3;
}

int Urgencia::prioridad() const
{
    return 2;
}
