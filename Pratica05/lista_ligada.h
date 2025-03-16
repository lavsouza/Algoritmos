#ifndef LISTA_LIGADA_H
#define LISTA_LIGADA_H

#include <iostream>
#include <stdexcept>
#include "lista.h"

template <class T>
class ListaLigada : public Lista<T> {
private:
    struct Node {
        T data;
        Node* next;

        Node(T d, Node* n = nullptr) : data(d), next(n) {}
    };

    Node* head;

public:
    ListaLigada(int capacidade) : Lista<T>(capacidade), head(nullptr){

    }

    ~ListaLigada() override {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    int tamanho() override {
        return this->tamanhoAtual;
    }

    int capacidade() {
        return this->capacidadeAtual;
    }


    void adiciona(T valor) override {
        if (this->tamanhoAtual >= this->capacidadeAtual) {
            throw std::runtime_error("Lista cheia");
        }

        Node* novoNo = new Node(valor);

        if (head == nullptr) {
            head = novoNo;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = novoNo;
        }
        this->tamanhoAtual++;
    }

    void insere(int pos, T valor) override {
        if (pos < 0 || pos >= this->tamanhoAtual + 1) {
            throw std::runtime_error("Posição inválida");
        }
        if (this->tamanhoAtual >= this->capacidadeAtual) {
            throw std::runtime_error("Lista cheia");
        }

        Node* novoNo = new Node(valor);
        int idx = pos - 1;
        if (pos == 0) {
            novoNo->next = head;
            head = novoNo;
        } else {
            Node* temp = head;
            for (int i = 0; i < idx - 1; ++i) {
                temp = temp->next;
            }
            novoNo->next = temp->next;
            temp->next = novoNo;
        }
        ++this->tamanhoAtual;
    }

    void remove(int pos) override {
        pos = pos - 1;
        if (pos < 0 || pos > this->tamanhoAtual) {
            throw std::runtime_error("Posição inválida: " + std::to_string(pos));
        }

        if (this->tamanhoAtual == 0) {
           throw std::runtime_error("Lista vazia");
        }

        Node* temp;

        // Caso especial: remover o primeiro nó
        if (pos == 0) {
            temp = head;
            head = head->next;
        } else {
            // Encontra o nó anterior ao que será removido
            Node* prev = head;
            for (int i = 0; i < pos - 1; ++i) {
                prev = prev->next;
                // Verifica se o próximo nó é nulo (segurança extra)
                if (prev == nullptr) {
                    throw std::runtime_error("Erro: ponteiro nulo encontrado.");
                }
            }
            // Remove o nó na posição 'pos'
            temp = prev->next;
            prev->next = temp->next;
        }

        // Libera a memória do nó removido
        delete temp;
        --this->tamanhoAtual;
    }

    T pega(int pos) override {
        if (pos < 1 || pos >= this->tamanhoAtual + 1) {
            throw std::runtime_error("Posição inválida");
        }

        int idx = pos - 1;

        Node* temp = head;
        for (int i = 0; i < idx; i++) {
            temp = temp->next;
        }
        return temp->data;
    }

    std::string exibe() override {
        if (this->tamanhoAtual == 0) {
            return "A lista está vazia!";
        }

        std::ostringstream oss;
        Node* temp = head;
        while (temp != nullptr) {
            oss << temp->data << " ";
            temp = temp->next;
        }
        return oss.str();
    }
};

#endif // LISTA_LIGADA_H
