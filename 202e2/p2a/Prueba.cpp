//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#include "Prueba.h"

Prueba::Prueba()=default;

void Prueba::encolar(int prioridad, int valor)
{
    queue.encolar(Dato(prioridad, valor));
}
void Prueba::imprimir()
{
    queue.prueba();
}
