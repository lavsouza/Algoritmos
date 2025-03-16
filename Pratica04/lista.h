//
// Created by lucas on 13/01/2025.
//

#ifndef LISTA_H
#define LISTA_H

#endif //LISTA_H

#include <iostream>
#include <stdexcept>
using namespace std;

template <class T>
class Lista {
private:
    T* itens;
    int capacidade;
    int tamanhoAtual;

public:
    Lista(int capacidade) : capacidade(capacidade), tamanhoAtual(0) {
        if (capacidade <= 0) {
            throw std::runtime_error("Capacidade deve ser maior que 0");
        }
        itens = new T[capacidade];
    }

    ~Lista() {
        delete[] itens;
    }

    void adiciona(const T& item) {
        if (tamanhoAtual == capacidade) {
            throw std::runtime_error("Lista cheia");
        }
        itens[tamanhoAtual++] = item;
    }

    T pega(int idx) {
        if (idx < 1 || idx > tamanhoAtual) {
            throw std::runtime_error("Indice invalido");
        }
        return itens[idx - 1];
    }

    void insere(int idx, const T& item) {
        if (tamanhoAtual == capacidade) {
            throw std::runtime_error("Lista cheia");
        }
        if (idx < 1 || idx > tamanhoAtual + 1) {
            throw std::runtime_error("Indice invalido");
        }

        // Desloca os itens para a direita
        for (int i = tamanhoAtual; i >= idx; i--) {
            itens[i] = itens[i - 1];
        }

        itens[idx - 1] = item;
        tamanhoAtual++;
    }

    void remove(int idx) {
        if (idx < 1 || idx > tamanhoAtual) {
            throw std::runtime_error("Indice invalido");
        }

        for (int i = idx - 1; i < tamanhoAtual - 1; i++) {
            itens[i] = itens[i + 1];
        }

        tamanhoAtual--;
    }

    void exibe() {
        for (int i = 0; i < tamanhoAtual; i++) {
            cout << itens[i] << " ";
        }
        cout << endl;
    }

    int tamanho() {
        return tamanhoAtual;
    }
};

