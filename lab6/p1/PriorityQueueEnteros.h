//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#ifndef INF281_PRIORITYQUEUEENTEROS_H
#define INF281_PRIORITYQUEUEENTEROS_H

#include <fstream>

int compInt(const void *a, const void *b);
void imprimeInt(const void *a);
void cargarCola(void *&cola);

std::ifstream iopen_file(const char* name, std::ios_base::openmode mode = std::ios_base::in);

#endif //INF281_PRIORITYQUEUEENTEROS_H
