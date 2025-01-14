//
// Created by lucas on 13/01/2025.
//

#ifndef FILA_H
#define FILA_H

#endif //FILA_H

#include <iostream>
#include <stdexcept>

template <class T>
class Fila {
private:
    T* itens;
    int capacidade;
    int tamanhoAtual;
    int inicio;
    int fim;

public:
    Fila(int cap) : capacidade(cap), tamanhoAtual(0), inicio(0), fim(0) {
        itens = new T[cap];
    }

    ~Fila() {
        delete[] itens;
    }

    void enfileira(const T& item) {
        if (cheia()) {
            throw std::runtime_error("Fila cheia");
        }
        itens[fim] = item;
        fim = (fim + 1) % capacidade;
        tamanhoAtual++;
    }

    T desenfileira() {
        if (vazia()) {
            throw std::runtime_error("Fila vazia");
        }
        T itemRemovido = itens[inicio];
        inicio = (inicio + 1) % capacidade;
        tamanhoAtual--;
        return itemRemovido;
    }

    int cheia() {
        return tamanhoAtual == capacidade;
    }

    int vazia() {
        return tamanhoAtual == 0;
    }

    int tamanho() {
        return tamanhoAtual;
    }
};