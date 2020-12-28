//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#ifndef INF281_PACIENTE_HPP
#define INF281_PACIENTE_HPP


class Paciente {
public:
    Paciente();
    Paciente(const Paciente &rhs);
    virtual ~Paciente();

    void setNombre(const char *val);
    void setCodMed(const char *val);
    void setDni(int val);

    void getNombre(char *ptr) const;
    void getCodMed(char *ptr) const;
    int getDni() const;

    bool isNull();

    Paciente& operator=(const Paciente &rhs);

    static void copystr(char *&dest, const char *src);

private:
    int dni;
    char *nombre;
    char *codMed;
};


#endif //INF281_PACIENTE_HPP
