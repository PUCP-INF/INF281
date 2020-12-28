//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#include "ArbolBBG.h"

int main(int argc, char **argv)
{
    ArbolBBG<int> arbol;

    arbol.insertar(1);
    arbol.insertar(2);
    arbol.insertar(3);
    arbol.insertar(123123);
    arbol.insertar(2763);

    arbol.imprimir();

    arbol.modificar(3, 15);

    arbol.imprimir();

    arbol.eliminar();

    return 0;
}