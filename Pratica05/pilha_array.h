//
// Created by lucas on 13/01/2025.
//

#ifndef PILHA_H
#define PILHA_H

#endif //PILHA_H

#include <stdexcept>
#include <iostream>
#include <sstream>
#include "pilha.h"


template <class T>
class PilhaArray : public Pilha<T> {
public:
    PilhaArray(int capacidade) : Pilha<T>(capacidade) {
        this->itens = new T[capacidade];
    }

    ~PilhaArray() {
        delete[] this->itens;
    }

    void empilha(T item) override {
        if (this->topo >= this->capacidade - 1) {
            throw std::out_of_range("Pilha cheia");
        }
        this->itens[++(this->topo)] = item;
    }

    T desempilha() override {
        if (this->topo < 0) {
            throw std::out_of_range("Pilha vazia");
        }
        return this->itens[(this->topo)--];
    }

    int tamanho() override {
        return this->topo + 1;
    }

    std::string verConteudo() override {
        if (this->topo < 0) {
            return "A pilha está vazia!";
        }
        std::ostringstream oss;
        oss << "Conteúdo da pilha (topo -> base): ";
        for (int i = this->topo; i >= 0; --i) {
            oss << this->itens[i] << " ";
        }
        return oss.str();
    }
};

