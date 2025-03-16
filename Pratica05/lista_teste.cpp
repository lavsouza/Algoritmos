/*
 * lista.cpp
 *
 *  Created on: 28 de set de 2017
 *      Author: ramide
 */
#include <iostream>
#include <stdexcept>
#include <string>
#include "lista_ligada.h"

#define MAX 10

void testaTamanho(ListaLigada<int> &lista, const char *subcaso, int tamanho) {
    std::cerr << "Testando tamanho() [" << subcaso << "]: ";
    if (lista.tamanho() != tamanho) {
        std::cerr << "FALHOU (tam = " << lista.tamanho() << ")" << std::endl;
        exit(1);
    }
    std::cerr << "OK" << std::endl;
}

int mainLista() {
    ListaLigada<int> lista(MAX);
    try {
        std::cerr << "Testando adiciona() [normal]: ";
        for (int i = 1; i <= MAX; i++) {
            lista.adiciona(i * 7);
        }
        std::cerr << "OK" << std::endl;
    } catch (...) {
        std::cerr << "FALHOU!" << std::endl;
        exit(1);
    }

    testaTamanho(lista, "cheia", MAX);

    try {
        std::cerr << "Testando adiciona() [overflow]: ";
        lista.adiciona(MAX + 1);
        std::cerr << "FALHOU!" << std::endl;
        exit(1);
    } catch (std::runtime_error &ex) {
        std::cerr << "OK (" << ex.what() << ")" << std::endl;
    }

    try {
        std::cerr << "Testando pega() [idx < 1]: ";
        lista.pega(0);
        std::cerr << "FALHOU!" << std::endl;
        exit(1);
    } catch (std::runtime_error &ex) {
        std::cerr << "OK (" << ex.what() << ")" << std::endl;
    }

    try {
        std::cerr << "Testando pega() [idx > tam]: ";
        lista.pega(MAX + 1);
        std::cerr << "FALHOU!" << std::endl;
        exit(1);
    } catch (std::runtime_error &ex) {
        std::cerr << "OK (" << ex.what() << ")" << std::endl;
    }

    std::cerr << "Testando pega() [todos]: ";
    for (int i = MAX; i >= 1; i--) {
        try {
            if (lista.pega(i) != i * 7) {
                std::cerr << "FALHOU em " << i << std::endl;
                lista.exibe();
                exit(1);
            }
        } catch (...) {
            std::cerr << "FALHOU em " << i << " (excecão)" << std::endl;
            exit(1);
        }
    }
    std::cerr << "OK" << std::endl;
    std::cerr << "Testando remove() [pares]: ";
    try {
        for (int i = MAX / 2; i >= 1; i--) {
            lista.remove(2 * i);
        }
    } catch (std::runtime_error &ex) {
        std::cerr << "FALHOU (" << ex.what() << ")" << std::endl;
        exit(1);
    }
    std::cerr << "OK" << std::endl;

    testaTamanho(lista, "metade", MAX / 2);

    std::cerr << "Testando pega() [impares]: ";
    for (int i = 1; i <= MAX / 2; i++) {
        try {
            if (lista.pega(i) != 7 * (((i - 1) * 2) + 1)) {
                std::cerr << "FALHOU em " << i << std::endl;
                exit(1);
            }
        } catch (...) {
            std::cerr << "FALHOU em " << i << " (exceção)" << std::endl;
            exit(1);
        }
    }
    std::cerr << "OK" << std::endl;

    std::cerr << "Testando insere() [pares]: ";

    lista.adiciona(MAX * 7);

    for (int i = MAX / 2 - 1; i >= 1; i--) {
        try {
            lista.insere(i + 1, 2 * i * 7);
        } catch (...) {
            std::cerr << "FALHOU em " << i << " (exceção)" << std::endl;
            exit(1);
        }
    }
    std::cerr << "OK" << std::endl;

    testaTamanho(lista, "cheia", MAX);

    std::cerr << "Testando pega() [todos, 2o round]: ";
    for (int i = MAX; i >= 1; i--) {
        try {
            if (lista.pega(i) != i * 7) {
                std::cerr << "FALHOU em " << i << " (valor = " << lista.pega(i) << ")" << std::endl;
                lista.exibe();
                exit(1);
            }
        } catch (...) {
            std::cerr << "FALHOU em " << i << " (exceção)" << std::endl;
            exit(1);
        }
    }
    std::cerr << "OK" << std::endl;

    std::cerr << "Testando remove() [tudo]: ";
    try {
        for (int i = 1; i <= MAX; i++) {
            lista.remove(1);
        }
    } catch (std::runtime_error &ex) {
        std::cerr << "FALHOU (" << ex.what() << ")" << std::endl;
        exit(1);
    }
    std::cerr << "OK" << std::endl;

    testaTamanho(lista, "vazia", 0);

    try {
        std::cerr << "Testando remove() [underflow]: ";
        lista.remove(1);
        std::cerr << "FALHOU!" << std::endl;
        exit(1);
    } catch (std::runtime_error &ex) {
        std::cerr << "OK (" << ex.what() << ")" << std::endl;
    }

    std::cerr << "*** TODOS OS TESTES OK! *** " << std::endl;

    return 0;
}


