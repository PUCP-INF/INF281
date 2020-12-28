//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#include "Cuentas.h"

int main(int argc, char **argv)
{
    Cuentas cuentas;
    cuentas.leerCuentas("Clientes.csv");
    cuentas.leerTiposDeCambio();
    cuentas.reporteDeCuentas("ReporteDeCuentas.txt", 'C');
    cuentas.ejecutarMovimientos();
    cuentas.reporteDeCuentas("ReporteDeCuentas.txt", 'A');
    return 0;
}