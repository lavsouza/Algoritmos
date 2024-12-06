#ifndef ARRANJO_H
#define ARRANJO_H

#include <iostream>
using namespace std;

class IndiceInvalido : public std::exception {
private:
    std::string mensagem;
public:
    IndiceInvalido(int idx, int tamanho) {
        mensagem = "Índice " + std::to_string(idx) + " fora dos limites do arranjo (0 a " + std::to_string(tamanho - 1) + ").";
    }

    const char* erro() const noexcept {
        return mensagem.c_str();
    }
};


template <class T>
class Arranjo {
    private:
        int tamanho; // tamanho do arranjo
        T * items; //items do arranjo

    public:
        Arranjo(int tam) {
            // instanciar o array de items com new (pratica 1) e setar tamanho;
            tamanho = tam;
            items = new T[tam];
            cout << "Arranjo Construido" << endl;
        }

        virtual ~Arranjo() {
            // destruir o array de items (prática 1);
            cout << "Arranjo Destruido" << endl;
            delete[] items;
        }

        virtual T get(int idx) const {
            if (idx < 0 || idx >= tamanho) {
                throw IndiceInvalido(idx, tamanho);
            }
            return items[idx];
        }

        virtual void set(int idx, const T& item) {
            if (idx < 0 || idx >= tamanho) {
                throw IndiceInvalido(idx, tamanho);
            }
            items[idx] = item;
        }

        virtual void exibir();
};

template<class T>
void Arranjo<T>::exibir() {
   // exibir cada item numa linha da forma "<idx>: <item>"
   for (int i = 0; i < tamanho; i++) {
        cout << i << ": " << items[i] << endl;
   }
}


#endif //ARRANJO_H
