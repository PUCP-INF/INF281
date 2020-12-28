//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#ifndef INF281_PRUEBA_H
#define INF281_PRUEBA_H

#include "PriorityQueue.h"
#include "Dato.h"

class Prueba {
public:
    Prueba();
    void encolar(int prioridad, int valor);
    void imprimir();

private:
    PriorityQueue<Dato> queue{};
};

#endif //INF281_PRUEBA_H
