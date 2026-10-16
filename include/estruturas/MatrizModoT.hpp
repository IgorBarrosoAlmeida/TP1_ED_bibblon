#ifndef MATRIZE_MODO_T_HPP
#define MATRIZE_MODO_T_HPP
#include "ArrayDinamico.hpp"
#include "Structs.hpp"
#include <iostream>
#include <stdexcept>

// consulta e atribuição de uma célula, remoção de
// célula, percurso de uma linha e percurso de uma coluna. Deve também expor as
// operações necessárias ao cálculo das métricas, incluindo o produto interno entre duas
// linhas esparsas.

// TO-DO: herança para evitar repetição
class MatrizModoT {
private:
    ArrayDinamico<Tripleta> tripletas;
    int l, c;
    void inserir(int id_item, int id_atributo, int modificador);

public:
    MatrizModoT(int l, int c);
    MatrizModoT();

    // TO-DO: adicionar no if de adicionar item e atributo na main
    void add_item();
    void add_atributo();

    int get_c();
    int get_l();
    ArrayDinamico<Tripleta> get_tripletas();
    int get(int id_item, int id_atributo);
    void set(int id_item, int id_atributo, int modificador);

    // Imprime itens que tem um atributo
    void print_coluna(int id_atributo);
    // Imprime atributos de um item
    void print_linha(int id_item);

    // TO-DO: suporte as operações necessárias para calculo das metricas
};

#endif