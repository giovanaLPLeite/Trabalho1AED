#ifndef LIVRO_H
#define LIVRO_H

#include <string>

using namespace std;

struct Livro{
    int ISBN;
    string titulo;
    string autor;
    string editora;
    string genero;
    int ano;
};

#endif