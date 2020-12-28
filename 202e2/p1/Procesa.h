//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#ifndef INF281_PROCESA_H
#define INF281_PROCESA_H

#include "NPaciente.h"

class Procesa {
public:
    Procesa();

    void lee(const char *ptr);
    void ordena();
    void imprime(const char *ptr);

    int numPac();

private:
    NPaciente pac[200]{};
};

#endif //INF281_PROCESA_H
