//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#ifndef INF281_CUENTAS_H
#define INF281_CUENTAS_H

#include "ArbolBBG.h"
#include "Cuenta.h"
#include "Moneda.h"
#include <map>

using std::map;

class Cuentas {
public:
    void leerCuentas(const char *filename);
    void leerTiposDeCambio();
    void ejecutarMovimientos();
    void reporteDeCuentas(const char *filename, char op) const;

private:
    class ArbolBBG<class Cuenta> arbClientes;
    map<char, class Moneda> monedas;
};

#endif //INF281_CUENTAS_H
