//
// Created by lucas on 19/01/2025.
//

#ifndef PILHA_LIGADA_H
#define PILHA_LIGADA_H

#endif //PILHA_LIGADA_H

#include <iostream>
#include <stdexcept>
#include <sstream>
#include "pilha.h"


template <class T>
class PilhaLigada : public Pilha<T> {
private:
    struct Node {
        T data;
        Node* next;

        Node(T d, Node* n = nullptr) : data(d), next(n) {}
    };

    Node* topo;
    T capacidadeAtual;
    int tamanhoAtual;

public:
    PilhaLigada(int capacidade) : Pilha<T>(capacidade), topo(nullptr), capacidadeAtual(capacidade), tamanhoAtual(0) {}

    ~PilhaLigada() {
        while (!estaVazia()) {
            desempilha();
        }
    }

    bool estaVazia() const {
        return topo == nullptr;
    }

    bool estaCheia() const {
        return tamanhoAtual == capacidadeAtual;
    }

    void empilha(T item) override {
        if (tamanhoAtual >= capacidadeAtual) {
            throw std::out_of_range("A pilha está cheia.");
        }

        Node* novoNo = new Node(item, topo);
        topo = novoNo;
        tamanhoAtual++;
    }

    T desempilha() override {
        if (estaVazia()) {
            throw std::out_of_range("A pilha está vazia.");
        }

        Node* noRemover = topo;
        T dado = noRemover->data;
        topo = topo->next;
        delete noRemover;
        tamanhoAtual--;

        return dado;
    }

    std::string verConteudo() override {
        if (estaVazia()) {
            return "A pilha está vazia!";
        }

        std::ostringstream oss;
        Node* atual = topo;
        oss << "Conteúdo da pilha (topo -> base): ";
        while (atual != nullptr) {
            oss << atual->data << " ";
            atual = atual->next;
        }

        return oss.str();
    }

    int tamanho() override {
        return tamanhoAtual;
    }

    int capacidade() const {
        return capacidadeAtual;
    }
};



