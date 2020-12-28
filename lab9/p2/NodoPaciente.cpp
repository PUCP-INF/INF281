//
// CODIGO: 20171878
// NOMBRE: TORO VERA CARLOS SANTOS
//

#include "NodoPaciente.h"

NodoPaciente::NodoPaciente()
{
    sig = nullptr;
    dato = nullptr;
}

NodoPaciente::~NodoPaciente()
{
    delete dato;
}