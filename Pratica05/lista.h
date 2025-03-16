#ifndef LISTA_H
#define LISTA_H

#include <stdexcept>
#include <sstream>

template <typename T>
class Lista {
    protected:
        int tamanhoAtual;
        int capacidadeAtual;

    public:
        Lista(int capacidade) : capacidadeAtual(capacidade), tamanhoAtual(0) {
        }

        virtual ~Lista() {
        }

        virtual int tamanho() = 0;

        virtual void adiciona(T item) = 0;

        virtual void insere(int pos, T item) = 0;

        virtual void remove(int pos) = 0;

        virtual T pega(int pos) {};

        virtual std::string exibe() = 0;
};
#endif // LISTA_H
