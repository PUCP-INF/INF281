//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#include "Prueba.h"

int main(int argc, char **argv)
{
    Prueba prueba;

    prueba.encolar(2, 3);
    prueba.encolar(4, 1);
    prueba.encolar(2, 1);
    prueba.encolar(3, 3);
    prueba.encolar(1, 1);
    prueba.encolar(3, 1);
    prueba.encolar(2, 4);
    prueba.encolar(1, 8);
    prueba.encolar(3, 5);
    prueba.encolar(3, 5);

    prueba.imprimir();
    return 0;
}