//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#include "Urgencia.h"

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
    os << getDni() << " ";
    getNombre(buff);
    os << buff << " ";
    getCodMed(buff);
    os << porcSeguro << " " << porcUrgencia << endl;
}

bool Urgencia::usaSeguro()
{
    if (porcSeguro == 0) return false;
    return true;
}

int Urgencia::prioridad()
{
    return 2;
}
