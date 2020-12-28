//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#include "Procesa.h"
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

Procesa::Procesa() = default;

void Procesa::lee(const char* ptr)
{
    ifstream file (ptr, ios::in);
    if (!file.is_open()) {
        cerr << "No se pudo abrir el archivo " << ptr << endl;
        exit(1);
    }
    int size = 0;
    while (true) {
        pac[size].lee(file);
        if (file.eof()) break;
        size++;
    }
}

int Procesa::numPac()
{
    int size = 0;
    while (!pac[size].isNull()) size++;
    return size;
}

// bubble sort
void Procesa::ordena()
{
    int size = numPac();
    for (int i = 0; i < size-1; ++i) {
        for (int j = 0; j < size-i-1; ++j) {
            if (pac[j].ordenar(pac[j+1])) {
                pac[j].swap(pac[j+1]);
            }
        }
    }
}

void Procesa::imprime(const char* ptr)
{
    ofstream reporte(ptr, ios::out);
    if (!reporte.is_open()) {
        cerr << "No se pudo abrir el archivo " << ptr << endl;
        exit(1);
    }
    int size = numPac();
    reporte << "INSTITUTO DE SALUD SA" << endl
            << setw(100) << setfill('=') << "" << endl
            << setfill(' ') << setw(50) << "" << "Orden de atencion de los pacientes" << endl
            << setw(100) << setfill('-') << "" << endl << endl
            << "No.    DNI         Paciente                               Edad              "
            << "Observacion                   Referencia" << endl;
    int riesgo = 0, apod = 0;
    for (int i = 0; i < size; ++i) {
        reporte << right << setw(3) << setfill(' ') << i + 1 << ")   ";
        pac[i].imprime(reporte);
        if (pac[i].observacion() == 1) {
            riesgo++;
        } else if (pac[i].observacion() == 2) {
            apod++;
        }
    }
    reporte << setw(100) << setfill('=') << "" << endl << endl
            << "Pacientes: " << size << "   Personas de Riesgo: " << riesgo << endl
            << "Menores de edad sin apoderado: " << apod << endl;
}
