#include "ArrayDinamico.hpp"
#include "Atributo.hpp"
#include "Aventureiro.hpp"
#include "Item.hpp"
#include <fstream>
#include <iostream>
#include <string>

// TO-DO: Tratar exceção
// TO-DO: Melhorar repetição de código
int main()
{
    std::string comando;
    std::ifstream arquivo("entrada.txt");

    // Listas
    ArrayDinamico<Atributo> atributos;
    ArrayDinamico<Item> itens;
    ArrayDinamico<Aventureiro> aventureiros;

    if (!arquivo.is_open()) {
        std::cout << "Erro ao abrir o arquivo!" << std::endl;
        return 1;
    }

    while (arquivo >> comando) {
        if (comando == "E") {
            // Migra o modo de armazenamento
            char modo;
            arquivo >> modo;

            // TO-DO: chamar migrar modo

            std::cout << comando << " " << modo << std::endl;
        } else if (comando == "A") {
            // Cadastra um atributo
            std::string nome_atributo;
            arquivo >> nome_atributo;
            Atributo novo_atributo(nome_atributo);

            atributos.add_elemento_final(novo_atributo);

            std::cout << comando << " " << novo_atributo.get_id() << std::endl;
        } else if (comando == "I") {
            // Cadastra um item
            std::string nome_item;
            arquivo >> nome_item;
            Item novo_item(nome_item);

            itens.add_elemento_final(novo_item);

            std::cout << comando << " " << novo_item.get_id() << std::endl;

        } else if (comando == "H") {
            // Cadastra um aventureiro
            std::string nome_aventureiro;
            arquivo >> nome_aventureiro;
            Aventureiro novo_aventureiro(nome_aventureiro);

            aventureiros.add_elemento_final(novo_aventureiro);

            std::cout << comando << " " << novo_aventureiro.get_id() << std::endl;
        }
    }

    arquivo.close();

    return 0;
}