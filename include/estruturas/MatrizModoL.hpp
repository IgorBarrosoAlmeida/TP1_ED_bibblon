#ifndef MATRIZ_MODO_L_HPP
#define MATRIZ_MODO_L_HPP
#include "ArrayDinamico.hpp"
#include "Structs.hpp"
#include <iostream>
#include <stdexcept>

class MatrizModoL {
private:
    Celula** cabeca_itens; // cabeca_itens[i]: celula cabeça da linha i
    Celula** cabeca_atributos; // cabeca_atributos[j]: celula cabeça da coluna j
    int l, c, tamanho;

    Celula* antLinha(int i, int j);
    Celula* antColuna(int i, int j);

public:
    MatrizModoL();
    MatrizModoL(int li, int col);
    ~MatrizModoL();

    void add_item();
    void add_atributo();

    int get_c();
    int get_l();
    int get(int id_item, int id_atributo);
    void set(int id_item, int id_atributo, int modificador);

    ArrayDinamico<Tripleta> get_coluna(int id_atributo) const;
    ArrayDinamico<Tripleta> get_linha(int id_item) const;

    void print_coluna(int id_atributo);
    void print_linha(int id_item);
};

#endif