//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#ifndef INF281_MONEDA_H
#define INF281_MONEDA_H

#include <fstream>

class Moneda {
public:
    Moneda();
    Moneda(const Moneda &rhs);
    ~Moneda();

    char getSimbolo() const;
    double getEquivalencia() const;
    void getNombre(char *ptr) const;

    void setSimbolo(char val);
    void setEquivalencia(double val);
    void setNombre(const char *val);

    void leer(std::ifstream &in);
    void imprimir(std::ofstream &out);

private:
    char simbolo;
    double equivalencia;
    char *nombre;
};

#endif //INF281_MONEDA_H
