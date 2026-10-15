#include "Atributo.hpp"

int Atributo::count = 0;

Atributo::Atributo()
{
    this->id = -1;
    this->nome = "";
}
Atributo::Atributo(const std::string& nome)
    : nome(nome)
{
    id = count++;
}

int Atributo::get_id()
{
    return this->id;
}

std::string Atributo::get_nome()
{
    return this->nome;
}
