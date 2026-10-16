#include "MatrizModoL.hpp"

MatrizModoL::MatrizModoL()
{
    this->l = 0;
    this->c = 0;
    this->tamanho = 0;
    this->cabeca_itens = NULL;
    this->cabeca_atributos = NULL;
}

MatrizModoL::MatrizModoL(int li, int col)
{
    this->l = li;
    this->c = col;
    this->tamanho = 0;

    this->cabeca_itens = new Celula*[this->l];
    this->cabeca_atributos = new Celula*[this->c];

    for (int i = 0; i < this->l; i++) {
        this->cabeca_itens[i] = new Celula { i, -1, 0, NULL, NULL };
    }

    for (int j = 0; j < this->c; j++) {
        this->cabeca_atributos[j] = new Celula { -1, j, 0, NULL, NULL };
    }
}

int MatrizModoL::get_c()
{
    return this->c;
}
int MatrizModoL::get_l()
{
    return this->l;
}

MatrizModoL::~MatrizModoL()
{
    for (int i = 0; i < this->l; i++) {
        Celula* p = this->cabeca_itens[i];
        while (p != NULL) {
            Celula* q = p->prox_item;
            delete p;
            p = q;
        }
    }

    for (int j = 0; j < this->c; j++) {
        delete this->cabeca_atributos[j];
    }

    delete[] this->cabeca_itens;
    delete[] this->cabeca_atributos;
}

void MatrizModoL::add_item()
{
    Celula* nova_cabeca = new Celula { { l, -1, 0 }, nullptr, nullptr };
    Celula** novas_cabecas = new Celula*[this->l + 1];

    for (int i = 0; i < l; ++i) {
        novas_cabecas[i] = this->cabeca_itens[i];
    }
    novas_cabecas[this->l] = nova_cabeca;

    delete[] this->cabeca_itens;
    this->cabeca_itens = novas_cabecas;
    this->l++;
}

void MatrizModoL::add_atributo()
{
    Celula* nova_cabeca = new Celula { { -1, c, 0 }, nullptr, nullptr };
    Celula** novas_cabecas = new Celula*[this->c + 1];

    for (int j = 0; j < c; ++j) {
        novas_cabecas[j] = this->cabeca_atributos[j];
    }
    novas_cabecas[this->c] = nova_cabeca;

    delete[] this->cabeca_atributos;
    this->cabeca_atributos = novas_cabecas;
    this->c++;
}

Celula* MatrizModoL::antLinha(int i, int j)
{
    Celula* p = this->cabeca_itens[i];

    while (p->prox_item != NULL && p->prox_item->tripleta.id_atributo < j) {
        p = p->prox_item;
    }

    return p;
}

Celula* MatrizModoL::antColuna(int i, int j)
{
    Celula* p = this->cabeca_atributos[j];

    while (p->prox_atributo != NULL && p->prox_atributo->tripleta.id_item < i) {
        p = p->prox_atributo;
    }

    return p;
}

int MatrizModoL::get(int id_item, int id_atributo)
{
    Celula* ant = antLinha(id_item, id_atributo);
    Celula* p = ant->prox_item;

    if (p != NULL && p->tripleta.id_atributo == id_atributo) {
        return p->tripleta.modificador;
    }
    return 0;
}

void MatrizModoL::set(int id_item, int id_atributo, int modificador)
{
    Celula* item_ant = antLinha(id_item, id_atributo);
    Celula* atributo_ant = antColuna(id_item, id_atributo);
    Celula* p = item_ant->prox_item;

    if (p != NULL && p->tripleta.id_atributo == id_atributo) {
        if (modificador != 0) {
            p->tripleta.modificador = modificador;
            return;
        }

        item_ant->prox_item = p->prox_item;
        atributo_ant->prox_atributo = p->prox_atributo;
        delete p;
        this->tamanho--;
    }
    if (modificador == 0)
        return;
    Celula* nova = new Celula { id_item, id_atributo, modificador,
        item_ant->prox_item, atributo_ant->prox_atributo };
    item_ant->prox_item = nova;
    atributo_ant->prox_atributo = nova;
    this->tamanho++;
}

ArrayDinamico<Tripleta> MatrizModoL::get_coluna(int id_atributo) const
{
    if (id_atributo < 0 || id_atributo >= c) {
        throw std::invalid_argument("Posição invalida");
    }

    ArrayDinamico<Tripleta> resultado;
    const Celula* p = this->cabeca_atributos[id_atributo]->prox_atributo;

    while (p != nullptr) {
        resultado.add_elemento_final(p->tripleta);
        p = p->prox_atributo;
    }

    return resultado;
}

ArrayDinamico<Tripleta> MatrizModoL::get_linha(int id_item) const
{
    if (id_item < 0 || id_item >= l) {
        throw std::invalid_argument("Posição invalida");
    }

    ArrayDinamico<Tripleta> resultado;
    const Celula* p = this->cabeca_itens[id_item]->prox_item;

    while (p != nullptr) {
        resultado.add_elemento_final(p->tripleta);
        p = p->prox_item;
    }

    return resultado;
}

void MatrizModoL::LI(int id_item)
{
    if (id_item < 0 || id_item >= this->l) {
        throw std::invalid_argument("Posição invalida");
    }
    Celula* p = this->cabeca_itens[id_item];

    if (p->prox_item == NULL) {
        std::cout << " VAZIO";
        return;
    }

    int i = 1;
    while (p->prox_item != NULL) {
        p = p->prox_item;
        Tripleta trip = p->tripleta;
        std::cout << " atributo_" << i << " " << trip.id_atributo << " " << trip.modificador;
        i++;
    }
}