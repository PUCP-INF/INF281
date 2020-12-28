//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#include "NPaciente.h"
#include "Emergencia.h"
#include "Urgencia.h"
#include "Ambulatorio.h"

NPaciente::NPaciente()
{
    pac = nullptr;
}

NPaciente::~NPaciente()
{
    delete pac;
}

void NPaciente::lee(std::istream &in)
{
    char tipo, _;
    in >> tipo >> _;
    if (tipo == 'E') {
        pac = new Emergencia;
    } else if (tipo == 'U') {
        pac = new Urgencia;
    } else if (tipo == 'A') {
        pac = new Ambulatorio;
    } else {
        return;
    }
    pac->leer(in);
}

void NPaciente::imprime(std::ostream& os)
{
    if (!isNull()) pac->imprimir(os);
}

bool NPaciente::ordenar(const NPaciente& other)
{
    return (pac->prioridad() < other.pac->prioridad()) ||
            (pac->prioridad() == other.pac->prioridad() && pac->getEdad() < other.pac->getEdad());
}

int NPaciente::observacion() const
{
    return pac->observacion();
}

void NPaciente::swap(NPaciente &other)
{
    Paciente *tmp = pac;
    pac = other.pac;
    other.pac = tmp;
}

bool NPaciente::isNull() const
{
    return pac == nullptr;
}
