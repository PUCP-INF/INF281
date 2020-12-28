//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#include "PriorityQueue.h"
#include "PriorityQueueEnteros.h"

int main(int argc, char **argv)
{
    void *cola;
    crear_cola_prioridad(cola);
    cargarCola(cola);
    prueba(cola, imprimeInt);
    return 0;
}