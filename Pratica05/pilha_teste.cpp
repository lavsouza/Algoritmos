/*
 * pilha.cpp
 *
 *  Created on: 10 de mar de 2020
 *      Author: IFPE
 */

#include <iostream>
#include <stdexcept>
#include <sstream>


#include "pilha_ligada.h"

#define MAX 10

using namespace std;

int mainPilha() {
	 PilhaLigada<int> pilha(MAX);

    try {
        std::cerr << "Testando empilha() [normal]: ";
        for (int i = 0; i < MAX; i++) {
            pilha.empilha(2 * i);
        }
        std::cerr << "OK" << std::endl;
    } catch (...) {
        std::cerr << "FALHOU!" << std::endl;
        return 1;
    }

    std::cerr << "Testando tamanho() [cheia]: ";
    if (pilha.tamanho() != MAX) {
        std::cerr << "FALHOU (tam = " << pilha.tamanho() << ")" << std::endl;
        std::cerr << "Teste (conteudo = " << pilha.verConteudo() << ")" << std::endl;
        return 1;
    }
    std::cerr << "OK" << std::endl;

    try {
        std::cerr << "Testando empilha() [overflow]: ";
        for (int i = 0; i < MAX + 1; i++) {
            pilha.empilha(i);
        }
        std::cerr << "FALHOU!" << std::endl;
        return 1;
    } catch (std::out_of_range &ex) {
        std::cerr << "OK (" << ex.what() << ")" << std::endl;
    }

    try {
        std::cerr << "Testando desempilha() [normal]: ";
        for (int i = (MAX - 1); i >= 0; i--) {
            if (pilha.desempilha() != 2 * i) {
                std::cerr << "FALHOU em " << i << std::endl;
                return 1;
            }
        }
        std::cerr << "OK" << std::endl;
    } catch (...) {
        std::cerr << "FALHOU (desempilha inesperado)!" << std::endl;
        return 1;
    }

    std::cerr << "Testando tamanho() [vazia]: ";
    if (pilha.tamanho() != 0) {
        std::cerr << "FALHOU (tam = " << pilha.tamanho() << ")" << std::endl;
        return 1;
    }
    std::cerr << "OK" << std::endl;

    try {
        std::cerr << "Testando desempilha() [underflow]: ";
        pilha.desempilha();
        std::cerr << "FALHOU!" << std::endl;
        return 1;
    } catch (std::out_of_range &ex) {
        std::cerr << "OK (" << ex.what() << ")" << std::endl;
    }

    std::cerr << "*** TODOS OS TESTES OK! ***" << std::endl;

    return 0;
}


