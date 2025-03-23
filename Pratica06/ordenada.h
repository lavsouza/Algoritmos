//
// Created by IFPE on 19/12/2024.
//

#ifndef PRATICA_06_ORDENADA_H
#define PRATICA_06_ORDENADA_H

#include <iostream>

using namespace std;

class ListaOrdenada {
private:
    int * itens;
    int tamanho, capacidade;
public:
    explicit ListaOrdenada(int cap) {
        this->capacidade = cap;
        this->tamanho = 0;
        itens = new int[cap];
    }

    ~ListaOrdenada() {
        delete [] itens;
    }

    void insere(int valor) {
        if (this->tamanho == this->capacidade) {
            throw std::runtime_error("Lista cheia");
        }

        int posicao = 0;
        while (posicao < tamanho && itens[posicao] < valor) {
            posicao++;
        }
        for (int i = tamanho; i > posicao; i--) {
            itens[i] = itens[i - 1];
        }

        itens[posicao] = valor;
        tamanho++;
        // Checar capacidade antes de inserir; lançar std::runtime_error se excedida
	    // Inserir valor no array de forma a manter ordenado
	    // Deslocar os elementos depois do valor para a direita
	    // Lembrar de incrementar o tamanho (numero de elementos)
    }

    void remove(int valor) {
        int posicao = buscaBinaria(0, tamanho - 1, valor);

        if (posicao == -1) {
            throw std::runtime_error("Indíce Inválido");
        }

        for (int i = posicao; i < tamanho - 1; i++) {
            itens[i] = itens[i + 1];
        }

        tamanho--;
    }

    int buscaSequencial(int valor) {
        for (int i = 0; i < tamanho; i++) {
            if (itens[i] == valor) {
                return i;
            } else if (itens[i] > valor) {
                return -1;
            }
        }
        return -1;
        // Procurar elemento no array de forma sequencial
	    // Retornar índice; ou -1 caso não encontrado
    }


    // Chama a versão privada que você deve implementar
    int buscaBinaria(int valor) {
        return buscaBinaria(0, tamanho - 1, valor);
    }

    // Checa se a lista está realmente ordenada.
    bool valida() {
        for (int i = 0; i < tamanho - 1; i++) {
            if (itens[i] > itens[i + 1]) return false;
        }
        return true;
    }

    // Exibe a lista na saída padrão.
    void exibe() {
        for (int i = 0; i < tamanho; i++) {
            cout << i << ": " << itens[i] << "; ";
        }
        cout << endl;
    }

private:

    int buscaBinaria(int inicio, int final, int valor) {
        if (inicio > final) return -1;
        int meio = (inicio + final) / 2;
        if (itens[meio] == valor){
            return meio;
        }
        else if (itens[meio] > valor){
            return buscaBinaria(inicio, meio - 1, valor);
        } else {
            return buscaBinaria(meio + 1, final, valor);
        }
    }

};

#endif //PRATICA_06_ORDENADA_H
