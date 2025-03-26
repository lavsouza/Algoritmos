/*
 * avl.cpp
 *
 *  Created on: 3 de nov de 2017
 *      Author: ramide
 */

#include <iostream>
#include "avl.h"

using namespace std;

// Execute com debug para ver que as chamadas de
//  BST::insert() e AVL::insert() se alternam na pilha de execu��o.
//  BST::insert() realiza a inser��o de fato, e na volta da recurs�o
//  AVL::insert() verifica se est� balanceado e faz as rota��es se preciso.
BinaryTree::Node * AVLTree::insert(BinaryTree::Node * root, int key) {
	root = BinaryTree::insert(root, key);

	root = rebalance(root);

	return root;
}

BinaryTree::Node * AVLTree::remove(BinaryTree::Node * root, int key) {
	root = BinaryTree::remove(root, key);

	root = rebalance(root);

	return root;
}

BinaryTree::Node * AVLTree::removeMax(BinaryTree::Node * root, int & max) {
	root = BinaryTree::removeMax(root, max);

	root = rebalance(root);

	return root;
}

BinaryTree::Node * AVLTree::rebalance(Node * node) {
	if (node == nullptr || balanced(node)) return node;

	if (leftHeavy(node)) {
		if (rightHeavy(node->left))
            node->left = rotateLeft(node->left);

        node = rotateRight(node);
	} else { // rightHeavy
		if (leftHeavy(node->right))
            node->right = rotateRight(node->right);

        node = rotateLeft(node);
	}

	ASSERT(balanced(node), "Rebalanceamento falhou!");
	return node;
}

// Realiza a rota��o a esquerda sobre "node" retornando a nova raiz
BinaryTree::Node * AVLTree::rotateLeft(Node * node) {
	if (node == nullptr || node->right == nullptr) {
		return node;
	}

	Node *newRoot = node->right;
	node->right = newRoot->left;
	newRoot->left = node;

	updateH(node);
	updateH(newRoot);

	return newRoot;
}

// Realiza a rotação à direita sobre "node" retornando a nova raiz
BinaryTree::Node * AVLTree::rotateRight(Node * node) {
	if (node == nullptr || node->left == nullptr) {
		return node;
	}

	Node *newRoot = node->left;
	node->left = newRoot->right;
	newRoot->right = node;

	updateH(node);
	updateH(newRoot);

	return newRoot;
}


void AVLTree::show(Node * root) {
	if (root == nullptr)
		return;
	show(root->left);
	cout << "(" << root->key << ", "
			<< root->height << ", "
			<< BF(root) << ") ";
	show(root->right);
}

int AVLTree::validate(Node * root, int &min, int &max) {
	int valid = BinaryTree::validate(root, min, max);

	return valid && balanced(root);
}
