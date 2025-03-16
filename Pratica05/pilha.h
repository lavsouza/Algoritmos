//
// Created by lucas on 19/01/2025.
//

#ifndef PILHA_H
#define PILHA_H

#endif //PILHA_H

#include <iostream>
#include <string>

template <typename T>
class Pilha {
    protected:
        T* itens;
        int topo;
        int capacidade;

    public:
        Pilha(int capacidade) : capacidade(capacidade), topo(-1) {
            itens = new T[capacidade];
        }

        virtual ~Pilha() {
            delete[] itens;
        }

        virtual void empilha(T item) = 0;

        virtual T desempilha() = 0;

        virtual int tamanho() = 0;

        virtual std::string verConteudo() = 0;
};

