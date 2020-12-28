//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#include "ListaDePacientes.h"
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
    ListaDePacientes lista;
    ifstream file("AtencionDeCitas.csv", ios::in);
    ofstream reporte("ReporteCitas.txt", ios::out);

    file >> lista;
    reporte << lista;

    return 0;
}