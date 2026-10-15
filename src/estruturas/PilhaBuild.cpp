#include "PilhaBuild.hpp"

PilhaBuild::PilhaBuild()
    : itens()
{
}

bool PilhaBuild::is_vazio()
{
    return this->itens.get_tamanho() == 0;
}

void PilhaBuild::equipar(int id_item)
{
    this->itens.add_elemento_final(id_item);
}

int PilhaBuild::desequipar()
{
    return this->itens.remove_elemento_final();
}