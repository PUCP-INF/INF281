//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#ifndef INF281_NPACIENTE_H
#define INF281_NPACIENTE_H

#include "Paciente.h"

// > 65 riesgo (no importa tipo) p1
// p2 si se toma el tipo
// < 18 (urgencia,ambulatorio)
// < 18 (emergencia) no es riesgo

class NPaciente {
public:
    NPaciente();
    ~NPaciente();

    void lee(std::istream &in);
    void imprime(std::ostream &os);

    bool isNull() const;
    int observacion() const;

    bool ordenar(const NPaciente &other);
    void swap(NPaciente &other);

private:
    Paciente *pac;
};

#endif //INF281_NPACIENTE_H
