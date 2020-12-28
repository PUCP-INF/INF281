//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#ifndef INF281_EMERGENCIA_H
#define INF281_EMERGENCIA_H

#include "Paciente.hpp"
#include <fstream>

class Emergencia: public Paciente {
public:
    Emergencia();
    Emergencia(const Emergencia &rhs);
    ~Emergencia() override;
    int getTelefonoRef() const;
    void setTelefonoRef(int telefono_ref);
    void getNombreRef(char *ptr) const;
    void setNombreRef(const char *val);

    Emergencia& operator=(const Emergencia &rhs);

    friend std::ostream& operator<<(std::ostream &os, const Emergencia &rhs);

private:
    int telefonoRef;
    char *nombreRef;
};

#endif //INF281_EMERGENCIA_H
