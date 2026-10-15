#include "Matrizes.hpp"

// ==================================
// Implementação da matriz no modo T
// ==================================
MatrizModoT::MatrizModoT()
    : tripletas()
{
    if (l < 0 || c < 0) {
        throw std::invalid_argument("Não é possível criar uma matriz com a quantidade de linhas ou colunas negativa");
    }

    this->l = 0;
    this->c = 0;
}

void MatrizModoT::add_item()
{
    this->l++;
}

void MatrizModoT::add_atributo()
{
    this->c++;
}

void MatrizModoT::inserir(int id_item, int id_atributo, int modificador)
{
    Tripleta nova_tripleta;
    nova_tripleta.id_item = id_item;
    nova_tripleta.id_atributo = id_atributo;
    nova_tripleta.modificador = modificador;

    if (id_item > this->l) {
        // Se for maior que a quantidade de linhas, aumenta a quantidade de linhas
        this->l = id_item;
    }
    if (id_atributo > this->c) {
        // O mesmo para a coluna
        this->c = id_atributo;
    }

    int p = this->tripletas.get_tamanho();
    if (p > 0 && (this->tripletas.get_elemento(p - 1).id_item > id_item)
        || (this->tripletas.get_elemento(p - 1).id_atributo == id_item
            && this->tripletas.get_elemento(p - 1).id_atributo > id_atributo)) {
        // Quando p == tamanho e a condição acima é verdadeira, é preciso criar um novo
        // elemento no vetor para copiar o elemento da posição this->tripletas[tamanho]
        this->tripletas.add_elemento_final(this->tripletas.get_elemento(p - 1));
        p--;
    } else {
        this->tripletas.add_elemento_final(nova_tripleta);
        return;
    }

    while (p > 0 && (this->tripletas.get_elemento(p - 1).id_item > id_item)
        || (this->tripletas.get_elemento(p - 1).id_atributo == id_item
            && this->tripletas.get_elemento(p - 1).id_atributo > id_atributo)) {
        // Movimenta o vetor até achar a posição do novo elemento
        this->tripletas.set_elemento(this->tripletas.get_elemento(p - 1), p);
        p--;
    }

    // Quando sai do while o p está na posição certa do novo elemento
    this->tripletas.set_elemento(nova_tripleta, p);
}

int MatrizModoT::get(int id_item, int id_atributo)
{
    if (id_item < 0 || id_item >= this->l || id_atributo < 0 || id_atributo >= this->c) {
        throw std::invalid_argument("Posição invalida");
    }

    // TO-DO: Busca binaria.
    for (int p = 0; p < this->tripletas.get_tamanho(); p++) {
        Tripleta trip = this->tripletas.get_elemento(p);
        if (trip.id_item == id_item && trip.id_atributo == id_atributo) {
            return trip.modificador;
        }
    }

    return 0;
}

void MatrizModoT::set(int id_item, int id_atributo, int modificador)
{
    if (id_item < 0 || id_item >= this->l || id_atributo < 0 || id_atributo >= this->c) {
        throw std::invalid_argument("Posição invalida");
    }

    // TO-DO: implementar com busca binaria
    for (int p = 0; p < this->tripletas.get_tamanho(); p++) {
        Tripleta trip = this->tripletas.get_elemento(p);
        if (trip.id_item == id_item && trip.id_atributo == id_atributo) {
            if (modificador == 0) {
                this->tripletas.remove_elemento_pos(p);
            } else {
                trip.modificador = modificador;
            }
            return;
        }
    }

    if (modificador != 0) {
        this->inserir(id_item, id_atributo, modificador);
    }
}

int MatrizModoT::remover(int id_item, int id_atributo)
{
    if (id_item < 0 || id_item >= this->l || id_atributo < 0 || id_atributo >= this->c) {
        throw std::invalid_argument("Posição invalida");
    }

    // TO-DO: implementar com busca binaria
    for (int p = 0; p < this->tripletas.get_tamanho(); p++) {
        Tripleta trip = this->tripletas.get_elemento(p);
        if (trip.id_item == id_item && trip.id_atributo == id_atributo) {
            int modificador = this->tripletas.remove_elemento_pos(p).modificador;
            return modificador;
        }
    }

    return 0;
}

void MatrizModoT::itens_por_atributo(int id_atributo)
{
    if (id_atributo < 0 || id_atributo >= this->c) {
        throw std::invalid_argument("Posição invalida");
    }

    // TO-DO: Implementar com busca binaria
    for (int p = 0; p < this->tripletas.get_tamanho(); p++) {
        Tripleta trip = this->tripletas.get_elemento(p);
        if (trip.id_atributo == id_atributo) {
            std::cout << " " << trip.id_item;
        }
    }
    std::cout << std::endl;
}

void MatrizModoT::atributo_por_item(int id_item)
{
    if (id_item < 0 || id_item >= this->c) {
        throw std::invalid_argument("Posição invalida");
    }

    for (int p = 0; p < this->tripletas.get_tamanho(); p++) {
        Tripleta trip = this->tripletas.get_elemento(p);
        if (trip.id_item == id_item) {
            std::cout << " " << trip.id_atributo;
        }
    }
    std::cout << std::endl;
}

// ==================================
// Implementação da matriz no modo L
// ==================================
