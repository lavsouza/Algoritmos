/*
 * avl.h
 *
 *  Created on: 2 de nov de 2017
 *      Author: ramide
 */

#ifndef AVL_H_
#define AVL_H_

#include "bst.h"

#include <algorithm> // max
using namespace std;

class AVLTree : public BinaryTree {
public:
    // Mesma interface que BinaryTree

private:
    // Fun��es herdadas

    Node * insert(Node * root, int key) override;
    Node * remove(Node * root, int key) override;
    Node * removeMax(Node * root, int & max) override;

    void show(Node * root) override;
    int validate(Node * root, int &min, int &max) override;

    // Fun��es novas

    static int BF(Node * node) { // Fator de balanceamento
		return H(node->left) - H(node->right);
	}

	static int balanced(Node * node) { // Balanceada?
		return node == nullptr || abs(BF(node)) < 2;
	}

	// Pesada � esquerda ou � direita?
	static int leftHeavy(Node * node) { return H(node->left) > H(node->right); }
	static int rightHeavy(Node * node) { return H(node->left) < H(node->right); }

	// Fun��es de balanceamento e rota��o
	static Node * rebalance(Node * node);
	static Node * rotateLeft(Node * node);
	static Node * rotateRight(Node * node);
};


#endif /* AVL_H_ */
