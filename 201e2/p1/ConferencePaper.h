//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#ifndef INF281_CONFERENCEPAPER_H
#define INF281_CONFERENCEPAPER_H

#include "Paper.h"
#include <fstream>

class ConferencePaper: public Paper {
public:
    ConferencePaper();
    ConferencePaper(int id, const char *title, const char *author_name, int publication_year,
            const char *conference_name, const char *host_country);
    ~ConferencePaper() override;

    void leerDatos(std::ifstream& is) override;
    void citar(std::ofstream& os) const override;

    void getConferenceName(char *ptr) const;
    void getHostCountry(char *ptr) const;

    void setHostCountry(const char *val);
    void setConferenceName(const char *val);
private:
    char *conference_name;
    char *host_country;
};

#endif //INF281_CONFERENCEPAPER_H
