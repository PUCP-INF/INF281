//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#include "PriorityQueueEnteros.h"
#include "PriorityQueue.h"
#include <iostream>

using namespace std;

int compInt(const void *a, const void *b)
{
    void **regA = static_cast<void**>(const_cast<void*>(a));
    void **regB = static_cast<void**>(const_cast<void*>(b));
    int prioA = *static_cast<int*>(regA[PRIO]);
    int prioB = *static_cast<int*>(regB[PRIO]);
    return prioA - prioB;
}

void imprimeInt(const void *a)
{
    void **reg = static_cast<void**>(const_cast<void*>(a));
    int val = *static_cast<int*>(reg[VAL]);
    int prio = *static_cast<int*>(reg[PRIO]);
    cout << prio << " " << val << endl;
}

void cargarCola(void *&cola)
{
    ifstream file = iopen_file("prueba.txt");
    int prio, val;
    while (true) {
        file >> prio >> val;
        if (file.eof()) break;
        encolar(cola, new int{prio}, new int{val}, compInt);
    }
}

ifstream iopen_file(const char* name, ios_base::openmode mode)
{
    ifstream file(name, mode);
    if (!file.is_open()) {
        cerr << "ERROR: No se pudo abrir el archivo: " << name << endl;
        exit(1);
    }
    return file;
}