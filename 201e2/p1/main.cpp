//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#include "Paper.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    ifstream file ("Papers.csv", ios::in);
    ofstream reporte ("ReportePruba.txt", ios::out);
    Paper *lstPapers[100];
    int size = 0;

    while (true) {
        file >> lstPapers[size];
        if (file.eof()) break;
        size++;
    }

    for (int i = 0; i < size; ++i) {
        lstPapers[i]->citar(reporte);
    }

    return 0;
}