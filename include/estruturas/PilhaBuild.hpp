#ifndef PILHA_BUILD_HPP
#define PILHA_BUILD_HPP
#include "ArrayDinamico.hpp"
#include "Item.hpp"

// ESC-IMP: A pilha guarda apenas o id do item para não precisar reservar memória para toda a estrutura do item
// ESC-IMP: Estou implementando com vetor pois a localidade de referencia é melhor e a implementção é mais simples

// Classe que implementa a estrutura pilha para guardar a build dos aventureiros
class PilhaBuild {
private:
    // Contém os IDs dos itens equipados
    ArrayDinamico<int> itens;

public:
    PilhaBuild();

    bool is_vazio();
    int get_tamanho();
    void equipar(int id_item);
    int desequipar();
    int get_item_equipado(int indice);
};

#endif