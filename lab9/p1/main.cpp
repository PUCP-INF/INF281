//
// CODIGO: 20171878
// NOMBRE: TORO VERA CARLOS SANTOS
//

#include "Paciente.h"
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
    Paciente *p1 = nullptr;
    ifstream file ("AtencionDeCitas.csv", ios::in);
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo AtencionDeCitas.csv" << endl;
        return 1;
    }

    while (true) {
        file >> p1;
        if (file.eof() || file.fail()) break;
        cout << p1;
        delete p1;
        p1 = nullptr;
    }

    return 0;
}
