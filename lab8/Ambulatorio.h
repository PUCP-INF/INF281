//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#ifndef INF281_AMBULATORIO_H
#define INF281_AMBULATORIO_H

#include "Paciente.hpp"
#include <fstream>

class Ambulatorio: public Paciente {
public:
    Ambulatorio();
    Ambulatorio(const Ambulatorio &rhs);
    ~Ambulatorio() override;

    double getPorcSeguro() const;
    void setPorcSeguro(double val);

    friend std::ostream& operator<<(std::ostream &os, const Ambulatorio &rhs);

private:
    double porcSeguro;
};


#endif //INF281_AMBULATORIO_H
