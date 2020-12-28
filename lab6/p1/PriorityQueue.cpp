//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#include "PriorityQueue.h"

void crear_cola_prioridad(void *&cola)
{
    cola = new void*[2]();
}

void encolar(void *&cola, void *prio, void *val, int (*comp) (const void*, const void*))
{
    void **&reg = reinterpret_cast<void**&>(cola),
         **nododato = new void*[2] {prio, val},
         **nodo = new void*[3] {nododato, nullptr, nullptr};
    if (vacio(cola)) {
        reg[INI] = nodo;
        reg[FIN] = nodo;
        return;
    }
    void **run = static_cast<void**>(reg[FIN]), **ant = nullptr;
    while (run) {
        if (comp(run[DATO], nododato) >= 0) break;
        ant = run;
        run = static_cast<void**>(run[ANT]);
    }
    if (!run) {
        nodo[SIG] = ant;
        ant[ANT] = nodo;
        reg[INI] = nodo;
    } else if (!ant) {
        nodo[ANT] = run;
        run[SIG] = nodo;
        reg[FIN] = nodo;
    } else {
        nodo[SIG] = ant;
        nodo[ANT] = run;
        run[SIG] = nodo;
        ant[ANT] = nodo;
    }
}

bool vacio(void *&cola)
{
    void **&reg = reinterpret_cast<void**&>(cola);
    if (reg[0] == nullptr && reg[1] == nullptr) return true;
    return false;
}

void* desencolar(void *&cola)
{
    void **&reg = reinterpret_cast<void**&>(cola);
    if (*reg) {
        void **nodo = reinterpret_cast<void**>(reg[INI]);
        reg[INI] = nodo[SIG];
        nodo[ANT] = nullptr;
        nodo = reinterpret_cast<void**>(nodo[SIG]);
        return nodo;
    }
    return nullptr;
}

void prueba(void *&cola, void (*print) (const void*))
{
    void **reg = static_cast<void**>(cola);
    void **run = static_cast<void**>(reg[INI]);
    while (run) {
        print(run[DATO]);
        run = static_cast<void**>(run[SIG]);
    }
}
