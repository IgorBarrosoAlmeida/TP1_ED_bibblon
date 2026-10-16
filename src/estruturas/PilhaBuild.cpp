#include "PilhaBuild.hpp"

PilhaBuild::PilhaBuild()
    : itens()
{
}

bool PilhaBuild::is_vazio()
{
    return this->itens.get_tamanho() == 0;
}

int PilhaBuild::get_tamanho()
{
    return this->itens.get_tamanho();
}

void PilhaBuild::equipar(int id_item)
{
    this->itens.add_elemento_final(id_item);
}

int PilhaBuild::desequipar()
{
    return this->itens.remove_elemento_final();
}

int PilhaBuild::get_item_equipado(int indice)
{
    return this->itens.get_elemento(indice);
}