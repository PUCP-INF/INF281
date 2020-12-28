//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#ifndef INF281_LISTADEPACIENTES_H
#define INF281_LISTADEPACIENTES_H

#include "Ambulatorio.h"
#include "Urgencia.h"
#include "Emergencia.h"

#include <fstream>

class ListaDePacientes {
public:
    ListaDePacientes();
    ~ListaDePacientes();

    void operator+(const Ambulatorio& rhs);
    void operator+(const Urgencia& rhs);
    void operator+(const Emergencia& rhs);

    int numAmb() const;
    int numUrg() const;
    int numEme() const;

    friend std::istream& operator>>(std::istream &is, ListaDePacientes &lista);
    friend std::ostream& operator<<(std::ostream &os, const ListaDePacientes &lista);

private:
    Ambulatorio *lAmb;
    Urgencia *lUrg;
    Emergencia *lEmer;
};



#endif //INF281_LISTADEPACIENTES_H
