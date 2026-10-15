#ifndef MATRIZES_HPP
#define MATRIZES_HPP
#include "ArrayDinamico.hpp"
#include "Estruturas.hpp"
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

public:
    MatrizModoT();

    // TO-DO: adicionar no if de adicionar item e atributo na main
    void add_item();
    void add_atributo();

    void inserir(int id_item, int id_atributo, int modificador);
    int get(int id_item, int id_atributo);
    void set(int id_item, int id_atributo, int modificador);
    int remover(int id_item, int id_atributo);

    // Imprime itens que tem um atributo
    void itens_por_atributo(int id_atributo);
    // Imprime atributos de um item
    void atributo_por_item(int id_item);

    // TO-DO: suporte as operações necessárias para calculo das metricas
};

#endif