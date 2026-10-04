#include "Item.hpp"

int Item::count = 0;

Item::Item(const std::string& nome)
    : nome(nome)
{
    id = ++count;
}

int Item::get_id()
{
    return id;
}

std::string Item::get_nome()
{
    return nome;
}
