#include "ArrayDinamico.hpp"
#include "Atributo.hpp"
#include "Aventureiro.hpp"
#include "Catalogo.hpp"
#include "FilaEncomenda.hpp"
#include "Item.hpp"
#include "Structs.hpp"
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
    FilaEncomenda fila_de_encomendas = FilaEncomenda(1); // TO-DO: Mudar depois para um número maior
    Catalogo catalogo;

    if (!arquivo.is_open()) {
        std::cout << "Erro ao abrir o arquivo!" << std::endl;
        return 1;
    }

    while (arquivo >> comando) {
        if (comando == "E") {
            // Migra o modo de armazenamento
            char modo;
            arquivo >> modo;

            catalogo.migrar_modo(modo);

            std::cout << comando << " " << modo << std::endl;
        } else if (comando == "A") {
            // Cadastra um atributo
            std::string nome_atributo;
            arquivo >> nome_atributo;
            Atributo novo_atributo(nome_atributo);

            atributos.add_elemento_final(novo_atributo);
            catalogo.add_atributo();

            std::cout << comando << " " << novo_atributo.get_id() << std::endl;
        } else if (comando == "I") {
            // Cadastra um item
            std::string nome_item;
            arquivo >> nome_item;
            Item novo_item(nome_item);

            itens.add_elemento_final(novo_item);
            catalogo.add_item();

            std::cout << comando << " " << novo_item.get_id() << std::endl;

        } else if (comando == "H") {
            // Cadastra um aventureiro
            std::string nome_aventureiro;
            arquivo >> nome_aventureiro;
            Aventureiro novo_aventureiro(nome_aventureiro);

            aventureiros.add_elemento_final(novo_aventureiro);

            std::cout << comando << " " << novo_aventureiro.get_id() << std::endl;
        } else if (comando == "F") {
            // Adicionar encomenda na fila
            int id_aventureiro, id_item;
            arquivo >> id_aventureiro;
            arquivo >> id_item;

            Encomenda nova_encomenda;
            nova_encomenda.id_aventureiro = id_aventureiro;
            nova_encomenda.id_item = id_item;

            int pos = fila_de_encomendas.enfileirar(nova_encomenda);
            std::cout << "F " << pos << std::endl;
        } else if (comando == "Z") {
            // Execução dos turnos de trabalho
            int turnos;
            ArrayDinamico<Encomenda> forjadas;

            arquivo >> turnos;
            // Trabalha nos turnos
            for (int i = 0; i < turnos; i++) {
                try {
                    Encomenda enc = fila_de_encomendas.desenfileirar();
                    forjadas.add_elemento_final(enc);

                    aventureiros.get_elemento(enc.id_aventureiro).build.equipar(enc.id_item);
                } catch (const std::out_of_range& e) {
                    // Tentou forjar, mas a fila estava vazia, portanto encerra os turnos
                    break;
                }
            }

            std::cout << "Z " << forjadas.get_tamanho() << std::endl;

            for (int i = 0; i < forjadas.get_tamanho(); i++) {
                Encomenda encomenda_forjada = forjadas.get_elemento(i);
                std::cout << "encomenda_" << i + 1 << " " << encomenda_forjada.id_aventureiro << " " << encomenda_forjada.id_item << " ";
            }
            std::cout << std::endl;
        } else if (comando == "D") {
            // Desequipar um item de um aventureiro
            int id_aventureiro, id_item = -1;
            arquivo >> id_aventureiro;

            try {
                id_item = aventureiros.get_elemento(id_aventureiro).build.desequipar();
            } catch (...) {
            }

            std::string nome_aventureiro = aventureiros.get_elemento(id_aventureiro).get_nome();
            if (id_item != -1) {
                std::string nome_item = itens.get_elemento(id_item).get_nome();

                std::cout << "D " << nome_aventureiro << " " << nome_item << std::endl;
            } else {
                std::cout << "D " << nome_aventureiro << " VAZIO" << std::endl;
            }
        } else if (comando == "M") {
            int id_item, id_atributo, modificador;
            arquivo >> id_item;
            arquivo >> id_atributo;
            arquivo >> modificador;

            catalogo.atualizar_modificador(id_item, id_atributo, modificador);
            std::cout << itens.get_elemento(id_item).get_nome() << " " << atributos.get_elemento(id_atributo).get_nome() << " " << modificador << std::endl;
        }
    }

    arquivo.close();

    return 0;
}