//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#ifndef INF281_URGENCIA_H
#define INF281_URGENCIA_H

#include "Paciente.hpp"
#include <fstream>

class Urgencia: public Paciente {
public:
    Urgencia();
    Urgencia(const Urgencia &rhs);
    ~Urgencia() override;
    double getPorcSeguro() const;
    void setPorcSeguro(double porc_seguro);
    double getPorcUrgencia() const;
    void setPorcUrgencia(double porc_urgencia);

    friend std::ostream& operator<<(std::ostream &os, const Urgencia &rhs);

private:
    double porcSeguro;
    double porcUrgencia;
};


#endif //INF281_URGENCIA_H
