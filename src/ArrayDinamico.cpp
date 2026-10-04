#include "ArrayDinamico.hpp"

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
T ArrayDinamico<T>::get_elemento(int index)
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
