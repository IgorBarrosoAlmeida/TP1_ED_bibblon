#include "ArrayDinamico.hpp"
#include "Atributo.hpp"
#include "Aventureiro.hpp"
#include "FilaEncomenda.hpp"
#include "Item.hpp"

template <typename T>
void ArrayDinamico<T>::aumentar_array()
{
    this->max = this->max * 2;
    T* array_aumentado = new T[this->max];

    for (int i = 0; i < tamanho; i++) {
        array_aumentado[i] = this->dados[i];
    }
    delete[] this->dados;

    this->dados = array_aumentado;
}

template <typename T>
ArrayDinamico<T>::ArrayDinamico()
{
    this->tamanho = 0;
    this->max = MAX_INICIAL;
    this->dados = new T[MAX_INICIAL];
}

// TO-DO: Entender essa implementação
template <typename T>
ArrayDinamico<T>::ArrayDinamico(const ArrayDinamico& outro)
    : tamanho(outro.tamanho)
    , max(outro.max)
    , dados(nullptr)
{
    T* copia = new T[this->max];
    try {
        for (int i = 0; i < this->tamanho; i++) {
            copia[i] = outro.dados[i];
        }
    } catch (...) {
        delete[] copia;
        throw;
    }
    this->dados = copia;
}

template <typename T>
ArrayDinamico<T>& ArrayDinamico<T>::operator=(const ArrayDinamico& outro)
{
    if (this != &outro) {
        ArrayDinamico copia(outro);
        T* dados_anteriores = this->dados;
        this->tamanho = copia.tamanho;
        this->max = copia.max;
        this->dados = copia.dados;
        copia.dados = dados_anteriores;
    }
    return *this;
}

template <typename T>
ArrayDinamico<T>::~ArrayDinamico()
{
    delete[] this->dados;
}

template <typename T>
int ArrayDinamico<T>::get_tamanho()
{
    return this->tamanho;
}

template <typename T>
int ArrayDinamico<T>::get_max()
{
    return this->max;
}

template <typename T>
T& ArrayDinamico<T>::get_elemento(int index)
{
    if (index < 0 || index >= this->tamanho) {
        throw std::out_of_range("Indice fora do limite");
    }

    return this->dados[index];
}

template <typename T>
const T& ArrayDinamico<T>::get_elemento(int index) const
{
    if (index < 0 || index >= this->tamanho) {
        throw std::out_of_range("Indice fora do limite");
    }

    return this->dados[index];
}

template <typename T>
void ArrayDinamico<T>::set_elemento(const T& elemento, int index)
{
    if (index < 0 || index >= this->tamanho) {
        throw std::out_of_range("Indice fora do limite");
    }

    this->dados[index] = elemento;
}

template <typename T>
void ArrayDinamico<T>::add_elemento_pos(const T& elemento, int index)
{
    if (index < 0 || index > this->tamanho) {
        throw std::out_of_range("Indice fora do limite para insercao");
    }

    if (this->tamanho == this->max) {
        this->aumentar_array();
    }

    // Insere no final
    if (index == this->tamanho) {
        this->dados[index] = elemento;
        this->tamanho++;
        return;
    }

    // Move os elementos a frente do index onde o novo elemento será inserido
    for (int i = this->tamanho; i > index; i--) {
        this->dados[i] = this->dados[i - 1];
    }
    // Insere o novo elemento
    this->dados[index] = elemento;
    this->tamanho++;
}

template <typename T>
void ArrayDinamico<T>::add_elemento_final(const T& elemento)
{
    this->add_elemento_pos(elemento, this->tamanho);
}

template <typename T>
void ArrayDinamico<T>::add_elemento_inicio(const T& elemento)
{
    this->add_elemento_pos(elemento, 0);
}

template <typename T>
T ArrayDinamico<T>::remove_elemento_pos(int index)
{
    if (this->tamanho == 0) {
        throw std::out_of_range("Array vazio");
    }

    if (index < 0 || index >= this->tamanho) {
        throw std::out_of_range("Indice fora do limite para remocao");
    }

    // Salva o elemento antes de sobrescrevê-lo para poder retorná-lo
    T elemento_removido = this->dados[index];

    // Desloca todos os elementos à direita do índice uma posição para a esquerda
    for (int i = index; i < this->tamanho - 1; i++) {
        this->dados[i] = this->dados[i + 1];
    }

    this->tamanho--;

    return elemento_removido;
}

template <typename T>
T ArrayDinamico<T>::remove_elemento_final()
{
    return this->remove_elemento_pos(this->tamanho - 1);
}

template <typename T>
T ArrayDinamico<T>::remove_elemento_inicio()
{
    return this->remove_elemento_pos(0);
}

template class ArrayDinamico<Atributo>;
template class ArrayDinamico<Item>;
template class ArrayDinamico<Aventureiro>;
template class ArrayDinamico<Encomenda>;
template class ArrayDinamico<Tripleta>;
template class ArrayDinamico<int>;