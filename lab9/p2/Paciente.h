//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#ifndef INF281_PACIENTE_H
#define INF281_PACIENTE_H

#include <iostream>

class Paciente {
public:
    Paciente();
    Paciente(const Paciente &orig);
    virtual ~Paciente();

    int getDni() const;
    void setDni(int dni);

    void getNombre(char *ptr) const;
    void getCodMed(char *ptr) const;

    void setNombre(const char *val);
    void setCodMed(const char *val);

    void readInfo(std::istream &is);

    virtual void leer(std::istream &is) = 0;
    virtual void imprimir(std::ostream &os) = 0;
    virtual int prioridad() = 0;
    virtual bool usaSeguro() = 0;

    static void copystr(char *&dest, const char *src);
private:
    int dni;
    char *nombre;
    char *codMed;
};

std::istream& operator>>(std::istream &is, Paciente *&pac);
std::ostream& operator<<(std::ostream &os, Paciente *&pac);

#endif //INF281_PACIENTE_H
