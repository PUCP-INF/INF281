//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#include "ConferencePaper.h"
#include <cstring>
#include <iostream>

using namespace std;

ConferencePaper::ConferencePaper()
{
    conference_name = nullptr;
    host_country = nullptr;
}

ConferencePaper::ConferencePaper(int id, const char* title, const char* author_name, int publication_year,
        const char* conference_name, const char* host_country):
Paper(id, title, author_name, publication_year),
conference_name(nullptr),
host_country(nullptr)
{
    setConferenceName(conference_name);
    setHostCountry(host_country);
}

ConferencePaper::~ConferencePaper()
{
    delete conference_name;
    delete host_country;
}

void ConferencePaper::getConferenceName(char* ptr) const
{
    strcpy(ptr, conference_name);
}

void ConferencePaper::getHostCountry(char* ptr) const
{
    strcpy(ptr, host_country);
}

void ConferencePaper::setHostCountry(const char* val)
{
    copystr(host_country, val);
}

void ConferencePaper::setConferenceName(const char* val)
{
    copystr(conference_name, val);
}

void ConferencePaper::leerDatos(std::ifstream& is)
{
    char str[200];
    is.getline(str, 200, ';');
    setConferenceName(str);
    is.getline(str, 200);
    setHostCountry(str);
}

void ConferencePaper::citar(std::ofstream& os) const
{
    char str[200];
    getAuthorName(str);
    os << str << " (" << getPublicationYear() << "). ";
    getTitle(str);
    os << str << ". " << conference_name << ". " << host_country << "." << endl;
}
