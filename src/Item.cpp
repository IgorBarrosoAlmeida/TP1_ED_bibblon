#include "Item.hpp"

int Item::count = 0;

Item::Item()
{
    this->id = -1;
    this->nome = "";
}

Item::Item(const std::string& nome)
    : nome(nome)
{
    this->id = count++;
}

int Item::get_id()
{
    return this->id;
}

std::string Item::get_nome()
{
    return this->nome;
}
