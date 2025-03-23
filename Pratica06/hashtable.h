#ifndef PRATICA_06_HASHTABLE_H
#define PRATICA_06_HASHTABLE_H

#include <vector>
#include <list>

using namespace std;

/* Tabela de Espalhamento como vector (array) de lists (listas encadeadas).
 * As listas lidam com colis�es (hashs que d�o o mesmo �ndice).
 */
template<class T_key, class T_value>
class Hashtable {
private:
    // vetor (array) de listas de pares
    // os pares s�o do tipo (chave, valor)
    // a lista � para o caso de colis�es no mesmo indice da tabela
    vector<list<pair<T_key, T_value>>> table;

    int capacity, size = 0;

public:
    explicit Hashtable(int cap) : capacity(cap), table(cap) {
        // ^ table(cap) inicializa o vector com tamanho inicial = cap
        if (cap <= 0) // testando se capacidade � valida
            throw std::runtime_error("Capacidade invalida");
    }

    ~Hashtable() {
        // nada a fazer aqui
        // vector table � desalocado automaticamente (n�o usamos new)
    }

    void insert(T_key key, T_value value) {
        if (size >= capacity)
        {
            throw std::runtime_error("Tabela cheia");
        }

        int idx = hash(key);
        if (idx == -1)
        {
            throw std::runtime_error("Indice gerado inválido");
        }
        table[idx].emplace_back(make_pair(key, value));

        size++;

        // Checar se tabela j� cheia; lan�ar std::runtime_error se for o caso
        // Calcular o indice usanda fun��o hash() [ver se��o private:]
        // Checar se �ndice retornado � valido (teste de sanidade); lan�ar exce��o se preciso
        // Acessar lista na tabela e colocar novo par ao final
        // Dica: use emplace_back() na lista para facilitar
        // Incremente o tamanho da tabela (size)
    }

    void remove(T_key key) {

        int idx = hash(key);

        if (idx < 0 || idx >= capacity) {
            throw std::runtime_error("Indice gerado inválido");
        }

        for (auto i = table[idx].begin(); i != table[idx].end(); ++i) {

            if (i->first == key) {
                table[idx].erase(i);
                size--;
                return;
            }
        }

        throw std::runtime_error("Chave nao encontrada");

        // Calcular o indice usanda fun��o hash() [ver se��o private:]
        // Checar se �ndice retornado � valido (teste de sanidade); lan�ar exce��o se preciso
        // Percorrer lista correpondente na tabela, procurando pelo elemento com a mesma chave
        // Dica: a lista � de pares; dado um item da lista, o primeiro elemento item.first � a chave
        // Ao achar o elemento, remover da lista (list.remove(elemento))
        // Decrementar tamanho.
    }

    T_value search(T_key key, T_value notFound) {

        int idx = hash(key);

        if (idx < 0 || idx >= capacity){
            throw std::runtime_error("Indice gerado inválido");
        }

        for (auto i = table[idx].begin(); i != table[idx].end(); ++i) {
            if (i->first == key) {
                 return i->second;
            }
        }

        return notFound;
       // Calcular o indice usanda fun��o hash() [ver se��o private:]
       // Checar se �ndice retornado � valido (teste de sanidade); lan�ar exce��o se preciso
       // Percorrer lista correpondente na tabela, procurando pelo elemento com a mesma chave
       // Ao achar o elemento, retornar o valor associado (elemento.second)
       // Caso n�o encontre, retornar par�metro notFound
    }

    // Exibe a tabela completa, com espa�os vazios e listas
    void show() {
        int i = 0;
        for (auto &list : table) {
            cout << i++ << ": ";
            for (auto &item : list)
                cout << "(" << item.first << " = " << item.second << ") ";
            cout << endl;
        }
    }

private:
    // Calcula o hash (indice) para chaves do tipo int
    int hash(int x) {
        return x % capacity;
    }

    // Calcula o hash (indice) para chaves do tipo string
    int hash(string key) {
        const int primo = 11;
        int hash_value = 0;

        for (char ch : key) {
            hash_value = (hash_value * primo + ch) % capacity;
        }

        return hash_value;
    }

};

#endif //PRATICA_06_HASHTABLE_H
