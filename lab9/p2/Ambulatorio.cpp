//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#include "Ambulatorio.h"

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
    os << getDni() << " ";
    getNombre(buff);
    os << buff << " ";
    getCodMed(buff);
    os << buff << " " << porcSeguro << endl;
}

int Ambulatorio::prioridad()
{
    return 1;
}

bool Ambulatorio::usaSeguro()
{
    if (porcSeguro == 0) return false;
    return true;
}
