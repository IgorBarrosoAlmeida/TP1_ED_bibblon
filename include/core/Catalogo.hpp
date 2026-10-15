#ifndef CATALOGO_HPP
#define CATALOGO_HPP
#include "Matrizes.hpp"

class Catalogo {
private:
    char modo_atual;
    MatrizModoT* matriz_t;
    MatrizModoL* matriz_l;

public:
    Catalogo();
    ~Catalogo();
    void atualizar_modificador(int id_item, int id_atributo, int valor);
    void migrar_modo(char novo_modo);
};

#endif