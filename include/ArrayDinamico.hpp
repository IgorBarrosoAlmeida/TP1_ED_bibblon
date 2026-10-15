#ifndef ARRAY_DINAMICO_HPP
#define ARRAY_DINAMICO_HPP
#define MAX_INICIAL 1 // TO-DO: mudar para ser uma variavel do construtor
#include <stdexcept>

// TAD para a criação de um array dinamico que tem um tamanho fixo
// alocado, porém esse tamanho pode dobrar caso precise de mais espaço
// Utilizei tamplete para o array ser utilizavel para diferentes tipos
template <typename T>
class ArrayDinamico {
private:
    int tamanho;
    int max;
    T* dados;

    void aumentar_array();

public:
    ArrayDinamico();
    ArrayDinamico(const ArrayDinamico& outro);
    ArrayDinamico& operator=(const ArrayDinamico& outro);
    ~ArrayDinamico();

    int get_tamanho();
    int get_max();

    T& get_elemento(int index);
    const T& get_elemento(int index) const;
    void set_elemento(const T& elemento, int index);

    void add_elemento_final(const T& elemento);
    void add_elemento_inicio(const T& elemento);
    void add_elemento_pos(const T& elemento, int index);

    T remove_elemento_final();
    T remove_elemento_inicio();
    T remove_elemento_pos(int index);
};

#endif