//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#ifndef INF281_PRIORITYQUEUE_H
#define INF281_PRIORITYQUEUE_H

enum NODO {DATO, ANT, SIG};
enum DATONODO {PRIO, VAL};
enum COLA {INI, FIN};

void crear_cola_prioridad(void *&cola);
void encolar(void *&cola, void *prio, void *val, int (*comp) (const void*, const void*));
void* desencolar(void *&cola);
void prueba(void *&cola, void (*print) (const void*));
bool vacio(void *&cola);

#endif //INF281_PRIORITYQUEUE_H
