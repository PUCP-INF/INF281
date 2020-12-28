//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#include "Procesa.h"

int main(int argc, char **argv)
{
    Procesa proc;
    proc.lee("Parte01_AtencionMedicaP.csv");
    proc.ordena();
    proc.imprime("ReporteAtencion.txt");

    return 0;
}