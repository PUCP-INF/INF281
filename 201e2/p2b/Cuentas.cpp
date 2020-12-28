//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#include "Cuentas.h"
#include <iostream>
#include <iomanip>

using namespace std;

void Cuentas::leerCuentas(const char* filename)
{
    ifstream file (filename, ios::in);
    if (!file.is_open()) {
        cerr << "No se pudo abrir el archivo " << filename << endl;
        exit(1);
    }
    Cuenta aux;
    while (true) {
        aux.leer(file);
        if (file.eof()) break;
        arbClientes.insertar(aux);
    }
}
void Cuentas::leerTiposDeCambio()
{
    ifstream file("TipoDeCambio.csv", ios::in);
    if (!file.is_open()) {
        cerr << "No se pudo abrir el archivo TipoDeCambio.csv" << endl;
        exit(1);
    }
    Moneda aux;
    while (true) {
        char tipo = file.peek();
        aux.leer(file);
        if (file.eof()) break;
        monedas.insert(make_pair(tipo, aux));
    }
}
void Cuentas::ejecutarMovimientos()
{
    ifstream file("Transacciones.csv", ios::in);
    if (!file.is_open()) {
        cerr << "No se pudo abrir el archivo Transacciones.csv" << endl;
        exit(1);
    }
    int codigo; char _, moneda, tipo; double monto, offset;
    while (true) {
        file >> codigo >> _;
        if (file.eof() || file.fail()) break;
        while (true) {
            file >> moneda >> monto >> _ >> tipo >> _;
            offset = monto * monedas[moneda].getEquivalencia();
            if (tipo == 'R') offset *= -1;
            arbClientes.modificar(codigo, offset);
            if (file.eof()) break;
            int pos = file.tellg(), tmp;
            file >> tmp;
            if (!file.fail()) {
                file.seekg(pos);    // retornar codigo de cliente
                break;
            } else {
                file.clear();
            }
        }
    }
}
void Cuentas::reporteDeCuentas(const char* filename, char op) const
{
    ofstream file;
    if (op == 'A') {
        file.open(filename, ios::out|ios::app);
        file << setw(100) << setfill('=') << "" << endl
             << "SALDO FINAL DE LAS CUENTAS" << endl
             << setw(100) << setfill('=') << "" << endl;
    } else {
        file.open(filename, ios::out);
        file << "ESTADOS DE CUENTAS" << endl;
        file << setw(100) << setfill('=') << "" << endl
             << "SALDO INICIAL DE LAS CUENTAS" << endl
             << setw(100) << setfill('=') << "" << endl;
    }
    arbClientes.imprimir(file);
}
