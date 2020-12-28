//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#ifndef INF281_JOURNALPAPER_H
#define INF281_JOURNALPAPER_H

#include "Paper.h"

class JournalPaper: public Paper {
public:
    JournalPaper();
    JournalPaper(int id, char *title, char *author_name, int publication_year,
            char *journal_name, int volume);
    ~JournalPaper() override;

    void setJournalName(const char *val);
    void getJournalName(char *ptr) const;

    void setVolume(int val);
    int getVolume() const;
    void leerDatos(std::ifstream& in) override;
    void citar(std::ofstream& out) const override;
private:
    char *journal_name;
    int volume;
};

#endif //INF281_JOURNALPAPER_H
