//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#include "JournalPaper.h"
#include <cstring>
#include <iostream>

using namespace std;

JournalPaper::JournalPaper()
{
    journal_name = nullptr;
    volume = 0;
}

JournalPaper::JournalPaper(int id, char* title, char* author_name, int publication_year,
        char* journal_name, int volume):
Paper(id, title, author_name, publication_year),
journal_name(nullptr),
volume(0)
{
    setJournalName(journal_name);
    setVolume(volume);
}

JournalPaper::~JournalPaper()
{
    delete journal_name;
}

void JournalPaper::setJournalName(const char* val)
{
    copystr(journal_name, val);
}

void JournalPaper::getJournalName(char* ptr) const
{
    strcpy(ptr, journal_name);
}

void JournalPaper::setVolume(int val)
{
    volume = val;
}

int JournalPaper::getVolume() const
{
    return volume;
}

void JournalPaper::leerDatos(std::ifstream& in)
{
    char str[200];
    in.getline(str, 200, ';');
    setJournalName(str);
    in >> volume;
}

void JournalPaper::citar(std::ofstream& out) const
{
    char str[200];
    getAuthorName(str);
    out << str << " (" << getPublicationYear() << "). ";
    getTitle(str);
    out << str << ". " << journal_name << ", " << volume << "." << endl;
}
