#ifndef ESTRUTURAS_HPP
#define ESTRUTURAS_HPP

// Struct que representa uma encomenda
struct Encomenda {
    int id_aventureiro;
    int id_item;
};

// Struct que representa uma tripleta da matriz de catalogo no modo T
// id_item = linha; id_atributo = coluna; modificador = valor;
struct Tripleta {
    int id_item;
    int id_atributo;
    int modificador;
};

#endif