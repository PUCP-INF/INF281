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
    void setDni(int val);

    int getEdad() const;
    void setEdad(int val);

    void getNombre(char *ptr) const;
    void getCodMed(char *ptr) const;

    void setNombre(const char *val);
    void setCodMed(const char *val);

    void readInfo(std::istream &is);

    virtual void leer(std::istream &is) = 0;
    virtual void imprimir(std::ostream &os) = 0;
    virtual int prioridad() const = 0;
    virtual int observacion() const = 0;

    static void copystr(char *&dest, const char *src);
private:
    int dni;
    int edad;
    char *nombre;
    char *codMed;
};

#endif //INF281_PACIENTE_H
