//
// Created by lucas on 19/01/2025.
//

#ifndef FILA_LIGADA_H
#define FILA_LIGADA_H

#endif //FILA_LIGADA_H

#include <iostream>
#include <stdexcept>

template <class T>
class Fila {
private:
    struct Node {
        int data;
        Node* next;

        Node(int d, Node* n = nullptr) : data(d), next(n) {}
    };

    Node* inicio;
    Node* fim;
    int capacidadeAtual;
    int tamanhoAtual;

public:
    Fila(int cap) : inicio(nullptr), fim(nullptr), capacidadeAtual(cap), tamanhoAtual(0) {}

    ~Fila() {
        while (!vazia()) {
            desenfileira();
        }
    }

    bool vazia() const {
        return inicio == nullptr;
    }

    bool cheia() const {
        return tamanhoAtual == capacidadeAtual;
    }

    void enfileira(int elemento) {
        if (cheia()) {
            throw std::overflow_error("A fila está cheia.");
        }

        Node* novoNo = new Node(elemento);
        if (fim != nullptr) {
            fim->next = novoNo;
        }
        fim = novoNo;

        if (inicio == nullptr) {
            inicio = fim;
        }

        tamanhoAtual++;
    }

    int desenfileira() {
        if (vazia()) {
            throw std::underflow_error("A fila está vazia.");
        }

        Node* noParaRemover = inicio;
        int dado = noParaRemover->data;
        inicio = inicio->next;
        if (inicio == nullptr) {
            fim = nullptr;
        }

        delete noParaRemover;
        tamanhoAtual--;

        return dado;
    }

    int consultaInicio() const {
        if (vazia()) {
            throw std::underflow_error("A fila está vazia.");
        }

        return inicio->data;
    }

    int tamanho() const {
        return tamanhoAtual;
    }

    int capacidade() const {
        return capacidadeAtual;
    }
};