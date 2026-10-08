#ifndef ATRIBUTO_HPP
#define ATRIBUTO_HPP

#include <string>

class Atributo {
private:
    static int count;
    int id;
    std::string nome;

public:
    Atributo();
    Atributo(const std::string& nome);

    int get_id();
    std::string get_nome();
};

#endif