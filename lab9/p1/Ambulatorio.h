//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#ifndef INF281_AMBULATORIO_H
#define INF281_AMBULATORIO_H

#include "Paciente.h"

class Ambulatorio: public Paciente {
public:
    Ambulatorio();
    Ambulatorio(const Ambulatorio &orig);

    double getPorcSeguro() const;
    void setPorcSeguro(double porcSeguro);

    ~Ambulatorio() override;
    void leer(std::istream &is) override;
    void imprimir(std::ostream &os) override;
    int prioridad() override;
    bool usaSeguro() override;

private:
    double porcSeguro;
};

#endif //INF281_AMBULATORIO_H
