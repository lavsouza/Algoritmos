/*
 * main.cpp
 *
 *  Created on: 30 de out de 2017
 *      Author: ramide
 */
#include <iostream>
#include <vector>
#include <set>

#include "bst.cpp"
#include "avl.cpp"

using namespace std;

void testTree(BinaryTree &tree, std::vector<int> values,
              bool sort_insert,
              bool test_succ_pred = true,
              bool test_seach_rem = true) {

    if (sort_insert) std::sort(values.begin(), values.end());

    try {
        cout << "Inserindo na arvore ... ";
        for (auto v : values) {
            tree.insert(v);
        }
        cout << "OK" << endl;

        if (tree.validate()) {
            cout << "Arvore eh valida: ";
            tree.show();
            cout << endl;
        } else {
            cout << "ERRO: Arvore NAO eh valida: ";
            tree.show();
            cout << endl;
            return;
        }

        std::vector<int> sorted = values;
        std::sort(sorted.begin(), sorted.end());

        if (test_succ_pred) {
            cout << "Testando Successor e Predecessor:" << endl;
            for (int i = 1; i < sorted.size() - 1; i++) {
                int val = sorted[i];
                int pred = sorted[i - 1];
                int succ = sorted[i + 1];

                bool succ_ok = tree.successor(val) == succ;
                bool pred_ok = tree.predecessor(val) == pred;

                cout << "Successor   de " << val << " == " << succ << "? " << (succ_ok ? "SIM" : "NAO") << endl;
                cout << "Predecessor de " << val << " == " << pred << "? " << (pred_ok ? "SIM" : "NAO") << endl;

                if (!succ_ok) {
                    cout << "ERRO: Successor errado!" << endl;
                }

                if (!pred_ok) {
                    cout << "ERRO: Predecessor errado!" << endl;
                }

                if (!succ_ok || !pred_ok) {
                    return;
                }
            }
        }

        if (test_seach_rem) {

            cout << "Testando Search e Remove:" << endl;

            int v_min = *sorted.begin();
            int v_max = *(sorted.end() - 1);
            int v_dif = v_max - v_min;

            // std::set implementada frequentemente com arvore binaria (red-black
            std::vector<int> search_vals = values;

            for (int i = 0; i < values.size(); i++) {
                int v = v_min + (rand() % (v_dif + 1));
                search_vals.push_back(v);
            }

            std::set<int> values_set;
            values_set.insert(values.begin(), values.end());

            for (int i = 0; i < values.size() * 1.5; i++) {
                int v = search_vals[rand() % search_vals.size()];
                bool found_values = values_set.find(v) != values_set.end();
                bool found_tree = tree.search(v);

                cout << "Procurando " << v << ": deve existir? " << (found_values ? "SIM" : "NAO");
                cout << " encontrado? " << (found_tree ? "SIM" : "NAO");

                if (found_values != found_tree) {
                    cout << "ERRO: Diverg�ncia na busca!" << endl;
                    return;
                }

                if (!found_tree) {
                    cout << endl;
                    continue;
                }

                values_set.erase(v);
                tree.remove(v);
                bool removed = !tree.search(v);
                cout << " removido? " << (removed ? "SIM" : "NAO");

                if (!removed) {
                    cout << endl << " ERRO: Diverg�ncia na busca!" << endl;
                    return;
                }

                bool valid = tree.validate();
                cout << " valida? " << (valid ? "SIM" : "NAO") << endl;

                if (!valid) {
                    cout << endl << " ERRO: Arvore invalida!" << endl;
                    return;
                }
            }
        }

        cout << "Testes OK!" << endl;

    } catch (const std::runtime_error & e) {
        cout << "ERRO: " << e.what() << endl;
        tree.show();
        cout << endl;
    }
}

int main() {
    std::vector<int> values = {10, 35, 22, 16, 1, 45, 17, 88, 62, 7}; // ordem de inser��o

    cout << "*** Testando BST: " << endl;
    BinaryTree bst;
    testTree(bst, values, false, true, true);

    cout << "*** Testando AVL: " << endl;
    AVLTree avl;
    testTree(avl, values, true, true, true);

    return 0;
}

