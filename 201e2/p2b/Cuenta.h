//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#ifndef INF281_CUENTA_H
#define INF281_CUENTA_H

#include <fstream>

class Cuenta {
public:
    Cuenta();
    Cuenta(const Cuenta &rhs);
    ~Cuenta();

    int getCodigo() const;
    double getSaldo() const;
    void getCliente(char *ptr) const;
    void getEstado(char *ptr) const;

    void setCodigo(int val);
    void setCliente(const char *val);
    void setSaldo(double val);
    void setEstado(const char *val);

    void leer(std::ifstream &in);
//    void imprimir(std::ofstream &out);

    bool operator<(const Cuenta &rhs) const;
    bool operator<=(const Cuenta &rhs) const;
    bool operator<(int cod) const;
    void operator+=(double offset);
    bool operator==(int cod) const;

private:
    int codigo;
    char *cliente;
    double saldo;
    char *estado;
};

std::ostream& operator<<(std::ostream &out, const Cuenta &rhs);

#endif //INF281_CUENTA_H
