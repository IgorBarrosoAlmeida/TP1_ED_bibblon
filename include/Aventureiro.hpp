#ifndef AVENTUREIRO_HPP
#define AVENTUREIRO_HPP

#include <string>

class Aventureiro {
private:
    static int count;
    int id;
    std::string nome;

public:
    Aventureiro(const std::string& nome);

    int get_id();
    std::string get_nome();
};

#endif