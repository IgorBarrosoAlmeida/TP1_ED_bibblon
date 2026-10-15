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

void Catalogo::atualizar_modificador(int id_item, int id_atributo, int valor)
{
    // TO-DO:
    if (this->modo_atual == 'T') {
        // matriz_t->inserir_ou_atualizar(id_item, id_atributo, valor);
    } else if (this->modo_atual == 'L') {
        // matriz_l->inserir_ou_atualizar(id_item, id_atributo, valor);
    }
}

void Catalogo::migrar_modo(char novo_modo)
{
    if (this->modo_atual == novo_modo)
        return; // Não faz nada se já está no modo

    if (novo_modo == 'T') {
        this->matriz_t = new MatrizModoT();

        // TO-DO:
        // Percorre a matriz_l inteira, e para cada celula chama:
        // matriz_t->inserir_ou_atualizar(item, atributo, valor);
        delete this->matriz_l;
        this->matriz_l = nullptr;
    } else if (novo_modo == 'L') {
        this->matriz_l = new MatrizModoL();

        // TO-DO:
        // Percorre a matriz_t inteira, e para cada celula chama:
        // matriz_l->inserir_ou_atualizar(item, atributo, valor);
        delete this->matriz_t;
        this->matriz_t = nullptr;
    }

    this->modo_atual = novo_modo;
}