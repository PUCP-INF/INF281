//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#include "ListaDePacientes.h"

int main(int argc, char **argv)
{
    ListaDePacientes l;
    l.creaLista("AtencionDeCitas.csv");
    l.imprimeLista("ReportePacientes.txt");
    return 0;
}
