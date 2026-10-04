#include "Atributo.hpp"

int Atributo::count = 0;

Atributo::Atributo(const std::string& nome)
    : nome(nome)
{
    id = ++count;
}

int Atributo::get_id()
{
    return id;
}

std::string Atributo::get_nome()
{
    return nome;
}
