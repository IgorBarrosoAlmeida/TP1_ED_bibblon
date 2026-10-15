#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

class Item {
private:
    static int count;
    int id;
    std::string nome;

public:
    Item();
    Item(const std::string& nome);

    int get_id();
    std::string get_nome();
};

#endif