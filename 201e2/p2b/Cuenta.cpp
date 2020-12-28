//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#include "Cuenta.h"
#include <cstring>
#include <iomanip>

using namespace std;

Cuenta::Cuenta()
{
    codigo = 0;
    cliente = nullptr;
    saldo = 0;
    estado = new char[6];
    strcpy(estado, "HABIL");
}
Cuenta::Cuenta(const Cuenta& rhs)
{
    codigo = rhs.codigo;
    saldo = rhs.saldo;
    cliente = nullptr;
    estado = nullptr;
    setCliente(rhs.cliente);
    setEstado(rhs.estado);
}
Cuenta::~Cuenta()
{
    delete cliente;
    delete estado;
}
int Cuenta::getCodigo() const
{
    return codigo;
}
double Cuenta::getSaldo() const
{
    return saldo;
}
void Cuenta::getCliente(char* ptr) const
{
    strcpy(ptr, cliente);
}
void Cuenta::getEstado(char* ptr) const
{
    strcpy(ptr, estado);
}
void Cuenta::setCodigo(int val)
{
    codigo = val;
}
void Cuenta::setCliente(const char* val)
{
    delete cliente;
    cliente = new char[strlen(val)+1];
    strcpy(cliente, val);
}
void Cuenta::setSaldo(double val)
{
    saldo = val;
}
void Cuenta::setEstado(const char* val)
{
    delete estado;
    estado = new char[strlen(val)+1];
    strcpy(estado, val);
}
void Cuenta::leer(std::ifstream& in)
{
    char _, str[100];
    in >> codigo >> _;
    in.getline(str, 100, ',');
    setCliente(str);
    in >> saldo;
}
bool Cuenta::operator<(const Cuenta &rhs) const
{
    if (codigo < rhs.codigo) {
        return true;
    } else {
        return false;
    }
}
bool Cuenta::operator<=(const Cuenta &rhs) const
{
    if (codigo <= rhs.codigo) {
        return true;
    } else {
        return false;
    }
}
bool Cuenta::operator<(int cod) const
{
    if (codigo < cod) {
        return false;
    } else {
        return true;
    }
}
void Cuenta::operator+=(double offset)
{
    saldo += offset;
    if (saldo < 0) {
        setEstado("SOBREGIRADO");
    } else {
        setEstado("HABIL");
    }
}
bool Cuenta::operator==(int cod) const
{
    return codigo == cod;
}
std::ostream& operator<<(std::ostream& out, const Cuenta& rhs)
{
    char str[200];
    out << rhs.getCodigo() << " ";
    rhs.getCliente(str);
    out << str << " " << rhs.getSaldo() << " ";
    rhs.getEstado(str);
    out << str << endl;
    return out;
}
