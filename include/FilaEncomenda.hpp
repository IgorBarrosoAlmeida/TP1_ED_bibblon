#ifndef FILA_ENCOMENDA_HPP
#define FILA_ENCOMENDA_HPP
#include "ArrayDinamico.hpp"
#include "Encomenda.hpp"

// ESC-IMP: Escolhi implementar com vetor pela locilidade de referência e escolhi ser fila circular
// para otimizar a remoção (sem precisar mover muitos elementos)

// Classe que implementa a estrutura fila circular para guardar a fila de encomendas
class FilaEncomenda {
private:
    Encomenda* dados;
    int capacidade;
    int tamanho;
    int frente;
    int tras;

    void aumentar_fila();

public:
    FilaEncomenda(int cap_inicial);
    ~FilaEncomenda();

    int enfileirar(const Encomenda& enc);
    Encomenda desenfileirar();
    bool is_vazia();
};

#endif