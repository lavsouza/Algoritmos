//
// Created by lucas on 13/01/2025.
//

#ifndef PILHA_H
#define PILHA_H

#endif //PILHA_H

#include <stdexcept>
#include <iostream>
#include <sstream>


template <class T>
class Pilha {
    private:
      T * itens;
      int topo;
      int capacidade;

    public:
        Pilha(int capacidade) : capacidade(capacidade), topo(-1){
            itens = new T[capacidade];
        }

        ~Pilha() {
            delete[] itens;
        }

        void empilha(T item) {
            if (topo >= capacidade - 1) {
              throw std::runtime_error("Pilha cheia");
            }
            itens[++topo] = item;
        }

        T desempilha() {
            if(topo < 0) {
              throw std::runtime_error("Pilha vazia");
            }
            return itens[topo--];
        }

        int tamanho() {
            return capacidade;
        }

    std::string verConteudo() {
            if (topo < 0) {
                return "A pilha está vazia!";
            }
            std::ostringstream oss;
            oss << "Conteúdo da pilha (topo -> base): ";
            for (int i = topo; i >= 0; --i) {
                oss << itens[i] << " ";
            }
            return oss.str();
        }
};
