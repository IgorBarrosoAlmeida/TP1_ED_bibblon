#include "FilaEncomenda.hpp"

// TO-DO: Revisar como funciona lista circular

void FilaEncomenda::aumentar_fila()
{
    int nova_capacidade = this->capacidade * 2;
    Encomenda* novo_array = new Encomenda[nova_capacidade];

    for (int i = 0; i < this->tamanho; i++) {
        int indice_real = (this->frente + i) % this->capacidade;
        novo_array[i] = this->dados[indice_real];
    }

    delete[] this->dados;
    this->dados = novo_array;
    this->capacidade = nova_capacidade;

    // Reseta os ponteiros virtuais
    this->frente = 0;
    this->tras = this->tamanho;
}

FilaEncomenda::FilaEncomenda(int cap_inicial = 4)
{
    this->capacidade = cap_inicial;
    this->dados = new Encomenda[this->capacidade];
    this->tamanho = 0;
    this->frente = 0;
    this->tras = 0;
}

FilaEncomenda::~FilaEncomenda()
{
    delete[] this->dados;
}

int FilaEncomenda::enfileirar(const Encomenda& enc)
{
    if (this->tamanho == this->capacidade) {
        aumentar_fila();
    }

    this->dados[this->tras] = enc;
    this->tras = (this->tras + 1) % this->capacidade;
    this->tamanho++;

    return this->tamanho;
}

Encomenda FilaEncomenda::desenfileirar()
{
    if (this->tamanho == 0) {
        throw std::out_of_range("Fila vazia");
    }

    Encomenda removida = this->dados[this->frente];
    this->frente = (this->frente + 1) % this->capacidade;
    this->tamanho--;

    return removida;
}

bool FilaEncomenda::is_vazia()
{
    return this->tamanho == 0;
}