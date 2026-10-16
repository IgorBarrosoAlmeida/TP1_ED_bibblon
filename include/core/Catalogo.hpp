#ifndef CATALOGO_HPP
#define CATALOGO_HPP
#include "MatrizModoL.hpp"
#include "MatrizModoT.hpp"

class Catalogo {
private:
    char modo_atual;
    MatrizModoT* matriz_t;
    MatrizModoL* matriz_l;

public:
    Catalogo();
    ~Catalogo();

    void add_item();
    void add_atributo();

    void atualizar_modificador(int id_item, int id_atributo, int modificador);
    void migrar_modo(char novo_modo);
};

#endif