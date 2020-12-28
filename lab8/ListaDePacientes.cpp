//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#include "ListaDePacientes.h"
#include <iostream>
#include <iomanip>

using namespace std;

ListaDePacientes::ListaDePacientes()
{
    lAmb = nullptr;
    lUrg = nullptr;
    lEmer = nullptr;
}

ListaDePacientes::~ListaDePacientes()
{
    delete[] lAmb;
    delete[] lUrg;
    delete[] lEmer;
}

std::istream& operator>>(std::istream& is, ListaDePacientes& lista)
{
    int dni, telef; char nombre[100], codigo[100], nombreref[100], tipo, _; double tarifa = 0, descuento = 0;
    while (true) {
        if (is.peek() == '\n' || is.eof() || is.fail()) break;
        is >> dni >> _;
        is.getline(nombre, 100, ',');
        is >> tipo >> _;
        is.getline(codigo, 100, ',');
        if (tipo == 'U') {
            is >> tarifa >> _ >> descuento >> _;
            Urgencia urg;
            urg.setNombre(nombre); urg.setDni(dni); urg.setCodMed(codigo); urg.setPorcSeguro(tarifa);
            urg.setPorcUrgencia(descuento);
            lista + urg;
        } else if (tipo == 'A') {
            is >> tarifa >> _;
            Ambulatorio amb;
            amb.setNombre(nombre); amb.setDni(dni); amb.setCodMed(codigo); amb.setPorcSeguro(tarifa);
            lista + amb;
        } else if (tipo == 'E') {
            is.getline(nombreref, 100, ',');
            is >> telef >> _;
            Emergencia eme;
            eme.setNombre(nombre); eme.setDni(dni); eme.setCodMed(codigo); eme.setNombreRef(nombreref);
            eme.setTelefonoRef(telef);
            lista + eme;
        }
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const ListaDePacientes& lista)
{
    os << setw(40) << "" << "INSTITUTO DE SALUD SA" << endl;
    os << setw(100) << setfill('=') << "" << endl
        << setw(40) << setfill(' ') << ""
        << "PACIENTES ATENDIDOS POR EMERGENCIA" << endl
        << setw(100) << setfill('-') << "" << endl;
    for (int i = 0; i < lista.numEme(); ++i) {
        os << i + 1 << ") " << lista.lEmer[i];
    }
    os << setw(100) << setfill('=') << "" << endl
       << setw(40) << setfill(' ') << ""
       << "PACIENTES ATENDIDOS POR URGENCIA" << endl
       << setw(100) << setfill('-') << "" << endl;
    for (int i = 0; i < lista.numUrg(); ++i) {
        os << i + 1 << ") " << lista.lUrg[i];
    }
    os << setw(100) << setfill('=') << "" << endl
       << setw(40) << setfill(' ') << ""
       << "PACIENTES ATENDIDOS POR AMBULATORIA" << endl
       << setw(100) << setfill('-') << "" << endl;
    for (int i = 0; i < lista.numAmb(); ++i) {
        os << i + 1 << ") " << lista.lAmb[i];
    }
    return os;
}

void ListaDePacientes::operator+(const Ambulatorio& rhs)
{
    int numel = numAmb();
    auto aux = new Ambulatorio[numel+2];
    for (int i = 0; i < numel; ++i) aux[i] = lAmb[i];
    aux[numel] = rhs;
    delete[] lAmb;
    lAmb = aux;
}

void ListaDePacientes::operator+(const Urgencia& rhs)
{
    int numel = numUrg();
    auto aux = new Urgencia[numel+2];
    for (int i = 0; i < numel; ++i) aux[i] = lUrg[i];
    aux[numel] = rhs;
    delete[] lUrg;
    lUrg = aux;
}

void ListaDePacientes::operator+(const Emergencia& rhs)
{
    int numel = numEme();
    auto aux = new Emergencia[numel+2];
    for (int i = 0; i<numel; ++i) aux[i] = lEmer[i];
    aux[numel] = rhs;
    delete[] lEmer;
    lEmer = aux;
}

int ListaDePacientes::numAmb() const
{
    if (!lAmb) return 0;
    int numel = 0;
    while (!lAmb[numel].isNull()) numel++;
    return numel;
}

int ListaDePacientes::numUrg() const
{
    if (!lUrg) return 0;
    int numel = 0;
    while (!lUrg[numel].isNull()) numel++;
    return numel;
}

int ListaDePacientes::numEme() const
{
    if (!lEmer) return 0;
    int numel = 0;
    while (!lEmer[numel].isNull()) numel++;
    return numel;
}
