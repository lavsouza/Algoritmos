#ifndef LISTA_ARRAY_H
#define LISTA_ARRAY_H

#include "lista.h"

template <class T>
class ListaArray : public Lista<T> {
private:
    T* itens;
    
public:
    ListaArray(int capacidade) : Lista<T>(capacidade){
        itens = new  T[capacidade];
    }

    int tamanho() override {
        return this->tamanhoAtual;
    }

    int capacidade() {
        return this->capacidadeAtual;
    }

    void adiciona(T item) override {
        if (this->tamanhoAtual >= this->capacidadeAtual) {
            throw std::runtime_error("Lista cheia");
        }
        itens[this->tamanhoAtual++] = item;
    }

    void insere(int idx, T item) override {
        if (this->tamanhoAtual == this->capacidadeAtual) {
            throw std::runtime_error("Lista cheia");
        }
        if (idx < 1 || idx > this->tamanhoAtual + 1) {
            throw std::runtime_error("Indice invalido");
        }

        for (int i = this->tamanhoAtual; i >= idx; i--) {
            itens[i] = itens[i - 1];
        }

        itens[idx - 1] = item;
        this->tamanhoAtual++;
    }

    void remove(int idx) override {
        if (idx < 1 || idx > this->tamanhoAtual) {
            throw std::runtime_error("Indice invalido");
        }

        for (int i = idx - 1; i < this->tamanhoAtual - 1; i++) {
            itens[i] = itens[i + 1];
        }

        this->tamanhoAtual--;
    }

    T pega(int idx) override {
        if (idx < 1 || idx > this->tamanhoAtual || idx > this->capacidadeAtual) {
            throw std::runtime_error("Indice invalido");
        }
        return itens[idx - 1];
    }

    std::string exibe() override {
        std::string result = "";
        for (int i = 0; i < this->tamanhoAtual; i++) {
            result += std::to_string(itens[i]) + " ";
        }
        return result;
    }
};

#endif //LISTA_ARRAY_H
