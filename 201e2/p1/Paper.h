//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#ifndef INF281_PAPER_H
#define INF281_PAPER_H

#include <fstream>

class Paper {
public:
    Paper();
    Paper(int id, const char *title, const char *author_name, int publication_year);
    virtual ~Paper();

    void setId(int val);
    void setTitle(const char *val);
    void setAuthorName(const char *val);
    void setPublicationYear(int val);

    int getId() const;
    int getPublicationYear() const;
    void getAuthorName(char *ptr) const;
    void getTitle(char *ptr) const;

    virtual void leerDatos(std::ifstream &in) = 0;
    virtual void citar(std::ofstream &out) const = 0;

    static void copystr(char *&dest, const char *src);

private:
    int id;
    char *title;
    char *author_name;
    int publication_year;
};

std::ifstream& operator>>(std::ifstream &in, Paper *&rhs);

#endif //INF281_PAPER_H
