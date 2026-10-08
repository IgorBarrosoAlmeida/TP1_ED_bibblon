#include "Aventureiro.hpp"

int Aventureiro::count = 0;

Aventureiro::Aventureiro()
{
    this->id = -1;
    this->nome = "";
}
Aventureiro::Aventureiro(const std::string& nome)
    : nome(nome)
{
    id = count++;
}

int Aventureiro::get_id()
{
    return this->id;
}

std::string Aventureiro::get_nome()
{
    return this->nome;
}
