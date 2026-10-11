#ifndef AVENTUREIRO_HPP
#define AVENTUREIRO_HPP

#include "PilhaBuild.hpp"
#include <string>

class Aventureiro {
private:
    static int count;
    int id;
    std::string nome;

public:
    PilhaBuild build;

    Aventureiro();
    Aventureiro(const std::string& nome);

    int get_id();
    std::string get_nome();
};

#endif