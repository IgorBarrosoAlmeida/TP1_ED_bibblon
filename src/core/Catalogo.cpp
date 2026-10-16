#include "Catalogo.hpp"

Catalogo::Catalogo()
{
    this->modo_atual = ' ';
    this->matriz_t = nullptr;
    this->matriz_l = nullptr;
}

Catalogo::~Catalogo()
{
    if (this->matriz_t != nullptr)
        delete this->matriz_t;
    if (this->matriz_l != nullptr)
        delete this->matriz_l;
}

void Catalogo::add_item()
{
    if (this->modo_atual == 'T') {
        this->matriz_t->add_item();
    } else if (this->modo_atual == 'L') {
        this->matriz_l->add_item();
    }
}

void Catalogo::add_atributo()
{
    if (this->modo_atual == 'T') {
        this->matriz_t->add_atributo();
    } else if (this->modo_atual == 'L') {
        this->matriz_l->add_atributo();
    }
}

void Catalogo::atualizar_modificador(int id_item, int id_atributo, int modificador)
{
    if (this->modo_atual == 'T') {
        matriz_t->set(id_item, id_atributo, modificador);
    } else if (this->modo_atual == 'L') {
        matriz_l->set(id_item, id_atributo, modificador);
    }
}

int Catalogo::get_modificador(int id_item, int id_atributo)
{
    if (this->modo_atual == 'T') {
        return matriz_t->get(id_item, id_atributo);
    }
    if (this->modo_atual == 'L') {
        return matriz_l->get(id_item, id_atributo);
    }
    return 0;
}

void Catalogo::migrar_modo(char novo_modo)
{
    if (this->modo_atual == novo_modo)
        return;

    if (novo_modo == 'T') {
        // Cria a matriz nas mesmas dimensões
        if (this->matriz_l != nullptr) {
            this->matriz_t = new MatrizModoT(this->matriz_l->get_l(), this->matriz_l->get_c());

            for (int i = 0; i < this->matriz_l->get_l(); i++) {
                ArrayDinamico<Tripleta> linha = this->matriz_l->get_linha(i);
                for (int j = 0; j < linha.get_tamanho(); j++) {
                    Tripleta elemento = linha.get_elemento(j);
                    this->matriz_t->set(elemento.id_item, elemento.id_atributo, elemento.modificador);
                }
            }

            delete this->matriz_l;
            this->matriz_l = nullptr;
        } else {
            this->matriz_t = new MatrizModoT();
        }

    } else if (novo_modo == 'L') {

        if (this->matriz_t != nullptr) {
            this->matriz_l = new MatrizModoL();
            ArrayDinamico<Tripleta> elementos = this->matriz_t->get_tripletas();

            for (int i = 0; i < elementos.get_tamanho(); i++) {
                Tripleta trip = elementos.get_elemento(i);
                this->matriz_l->set(trip.id_item, trip.id_atributo, trip.modificador);
            }

            delete this->matriz_t;
            this->matriz_t = nullptr;
        } else {
            this->matriz_l = new MatrizModoL();
        }
    }

    this->modo_atual = novo_modo;
}

void Catalogo::LI(int id_item)
{
    if (this->modo_atual == 'T') {
        this->matriz_t->LI(id_item);
    } else if (this->modo_atual == 'L') {
        this->matriz_l->LI(id_item);
    }
}

void Catalogo::LA(int id_atributo)
{
    if (this->modo_atual == 'T') {
        this->matriz_t->LA(id_atributo);
    } else if (this->modo_atual == 'L') {
        this->matriz_l->LA(id_atributo);
    }
}