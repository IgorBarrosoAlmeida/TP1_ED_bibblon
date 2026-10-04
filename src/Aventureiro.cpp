#include "Aventureiro.hpp"

int Aventureiro::count = 0;

Aventureiro::Aventureiro(const std::string& nome)
    : nome(nome)
{
    id = ++count;
}

int Aventureiro::get_id()
{
    return id;
}

std::string Aventureiro::get_nome()
{
    return nome;
}
