//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#include "ListaDePacientes.h"
#include <fstream>
#include <iomanip>

using namespace std;

ListaDePacientes::ListaDePacientes()
{
    lista = nullptr;
}

ListaDePacientes::~ListaDePacientes()
{
    NodoPaciente *sale;
    while (true) {
        sale = lista;
        if (!sale) break;
        lista = lista->sig;
        delete sale;
    }
}

void ListaDePacientes::creaLista(const char *filename)
{
    ifstream file(filename, ios::in);
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo AtencionDeCitas.csv" << endl;
        exit(1);
    }
    Paciente *p1;
    while (true) {
        file >> p1;
        if (file.eof() || file.fail()) break;
        insertar(p1);
        p1 = nullptr;
    }
}

void ListaDePacientes::insertar(Paciente *&pac)
{
    NodoPaciente *p = lista, *ant = nullptr, *nuevo;
    nuevo = new NodoPaciente;
    nuevo->dato = pac;
    while (p) {
        if (p->dato->prioridad() > pac->prioridad()) break;
        ant = p;
        p = p->sig;
    }
    nuevo->sig = p;
    if (ant != nullptr) ant->sig = nuevo;
    else lista = nuevo;
}

void ListaDePacientes::imprimeLista(const char *filename)
{
    ofstream out (filename, ios::out);
    if (!out) {
        cerr << "Error: no se pudo abrir el archivo " << filename << endl;
        exit(1);
    }
    out << "INSTITUTO DE SALUD S.A." << endl;
    int pacSeguro = 0, prio = 0, num;
    NodoPaciente *p = lista;
    while (p) {
        if (p->dato->usaSeguro()) pacSeguro++;
        if (prio != p->dato->prioridad()) {
            num = 0;
            prio = p->dato->prioridad();
            if (prio == 1) {
                out << setfill('=') << setw(100) << "" << endl
                    << "PACIENTES ATENDIDOS DE MANERA AMBULATORIA" << endl
                    << setfill('-') << setw(100) << "" << endl;
            } else if (prio == 2) {
                out << setfill('=') << setw(100) << "" << endl
                    << "PACIENTES ATENDIDOS POR URGENCIA" << endl
                    << setfill('-') << setw(100) << "" << endl;
            } else {
                out << setfill('=') << setw(100) << "" << endl
                    << "PACIENTES ATENDIDOS POR EMERGENCIA" << endl
                    << setfill('-') << setw(100) << "" << endl;
            }
        }
        num++;
        out << setfill(' ') << setw(2) << num << ") ";
        out << p->dato;
        p = p->sig;
    }
    out << setfill('=') << setw(100) << "" << endl << endl
        << "Atendidos por seguro: " << pacSeguro << " pacientes" << endl;
}