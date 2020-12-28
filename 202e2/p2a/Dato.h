//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#ifndef INF281_DATO_H
#define INF281_DATO_H

#include <iostream>

class Dato {
public:
    Dato(int prioridad, int valor);

    void setPrioridad(int val);
    void setValor(int val);

    int getPrioridad() const;
    int getValor() const;

    int operator-(const Dato &rhs) const;

private:
    int prioridad;
    int valor;
};

std::ostream& operator<<(std::ostream &os, const Dato &rhs);

#endif //INF281_DATO_H
