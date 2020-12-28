//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#include "Paper.h"
#include "ConferencePaper.h"
#include "JournalPaper.h"
#include <cstring>

Paper::Paper()
{
    id = 0;
    title = nullptr;
    author_name = nullptr;
    publication_year = 0;
}

Paper::Paper(int id, const char* title, const char* author_name, int publication_year):
Paper()
{
    setId(id);
    setTitle(title);
    setAuthorName(author_name);
    setPublicationYear(publication_year);
}

Paper::~Paper()
{
    delete title;
    delete author_name;
}

std::ifstream& operator>>(std::ifstream& in, Paper *&rhs)
{
    char tipo, _, str[200]; int val;
    in >> tipo >> _;
    if (tipo == 'C') {
        rhs = new ConferencePaper;
    } else if (tipo == 'J') {
        rhs = new JournalPaper;
    }
    in >> val >> _;
    rhs->setId(val);
    in.getline(str, 200, ';');
    rhs->setAuthorName(str);
    in >> val >> _;
    rhs->setPublicationYear(val);
    in.getline(str, 200, ';');
    rhs->setTitle(str);
    rhs->leerDatos(in);
    return in;
}

void Paper::setId(int val)
{
    id = val;
}

void Paper::setTitle(const char* val)
{
    copystr(title, val);
}

void Paper::setAuthorName(const char* val)
{
    copystr(author_name, val);
}

void Paper::setPublicationYear(int val)
{
    publication_year = val;
}

int Paper::getId() const
{
    return id;
}

int Paper::getPublicationYear() const
{
    return publication_year;
}

void Paper::getAuthorName(char* ptr) const
{
    strcpy(ptr, author_name);
}

void Paper::getTitle(char* ptr) const
{
    strcpy(ptr, title);
}

void Paper::copystr(char*& dest, const char* src)
{
    delete dest;
    dest = new char[strlen(src)+1];
    strcpy(dest, src);
}
