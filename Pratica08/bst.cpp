/*
 * binarytree.cpp
 *
 *  Created on: 30 de out de 2017
 *      Author: ramide
 */

#include <iostream>
#include <climits> // INT_MIN e INT_MAX

#include "bst.h"

BinaryTree::Node * BinaryTree::insert(BinaryTree::Node * _root, int key) {
	if (_root == nullptr) {
		return new Node(key); // Cria um novo nó se a árvore estiver vazia
	}

	if (key < _root->key) {
		_root->left = insert(_root->left, key); // Insere à esquerda
	} else if (key > _root->key) {
		_root->right = insert(_root->right, key); // Insere à direita
	}

	updateH(_root); // Atualiza a altura do nó
	return _root;
}

BinaryTree::Node * BinaryTree::search(BinaryTree::Node * _root, int key) {
	if (_root == nullptr || _root->key == key) {
		return _root;
	}

	if (key < _root->key) {
		return search(_root->left, key);
	} else {
		return search(_root->right, key);
	}
}


void BinaryTree::show(Node * _root) {
	if (_root == nullptr) {
		return;
	}

	show(_root->left);

	std::cout << "(" << _root->key << ", " << _root->height << ") ";

	show(_root->right);
}

BinaryTree::Node * BinaryTree::remove(BinaryTree::Node * _root, int key) {

	if (_root == nullptr) return nullptr; // (sub)�rvore vazia, nada a fazer

	if (key == _root->key) { // Chave encontrada!
		if (_root->left != nullptr && _root->right != nullptr) { // Caso 3
			int maxLeft;
			// Removo o maior filho da esquerda e
			// substituo o valor do n� atual com o valor que era dele
			_root->left = removeMax(_root->left, maxLeft);
            _root->key = maxLeft;
		} else { // Casos 1 e 2
			Node * tmp = _root;
            _root = (_root->right != nullptr) ? _root->right : _root->left;
			delete tmp;
		}
	} else {
		if (key > _root->key)
            _root->right = remove(_root->right, key);
		else
            _root->left = remove(_root->left, key);
	}

	// Lembrar sempre de atualizar a altura; importante para a AVL
	if (_root != nullptr) updateH(_root);

	return _root;
}

BinaryTree::Node * BinaryTree::removeMax(BinaryTree::Node * _root, int & max) {
	if (_root == nullptr) throw std::runtime_error("N�o deveria estar vazia");

	if (_root->right != nullptr) {
        _root->right = removeMax(_root->right, max);
	} else {
		max = _root->key;
		Node * tmp = _root;
        _root = _root->left;
		delete tmp;
	}

	if (_root != nullptr)
		updateH(_root);

	return _root;
}

// Acha n� predecessor (pred) a chave (key)
void BinaryTree::predecessor(Node * _root, Node * & pred, int key) {
	if (_root == nullptr) return;

	if (_root->key == key) { 		// Chave encontrada
		_root = _root->left;			// Desce a esquerda, pred n�o � mexido inicialmente
		while (_root != nullptr) {
			pred = _root;			// pred vai ser o elemento mais a direita
			_root = _root->right;
		}
	} else {
		if (key < _root->key)		// Chave se encontra a esquerda da raiz
			// n�o mexemos em pred aqui
			predecessor(_root->left, pred, key);
		else						// Chave se encontra a direita
			// No caso de predecessor, pred � atualizado quando descemos a direita
			predecessor(_root->right, pred = _root, key);
	}
}

// Acha n� sucessor (succ) a chave (key)
void BinaryTree::successor(Node * _root, Node * & succ, int key) {
	if (_root == nullptr) {
		return;
	}

	if (_root->key > key) {
		succ = _root;
		successor(_root->left, succ, key);
	} else {
		successor(_root->right, succ, key);
	}
}

// Valida a �rvore
// min e max s�o o menor e o maior valores contidas na �rvore, respectivamente
int BinaryTree::validate(Node * _root, int &min, int &max) {

	if (_root == nullptr) { // �rvore vazia � v�lida
		min = INT_MAX;
		max = INT_MIN;
		return 1;
	}

	int lmin, lmax; // menor e maior a esquerda
	int rmin, rmax; // menor e maior a direita

	// Se �rvore � esquerda � inv�lida ou maior a esquerda > raiz ent�o INV�LIDA
	if (!validate(_root->left, lmin, lmax) || (lmax > _root->key)) return 0;

	// Se �rvore � direita � inv�lida ou menor � direita < raiz ent�o INV�LIDA
	if (!validate(_root->right, rmin, rmax) || (rmin < _root->key)) return 0;

	// Computando menor e maior para �rvore em _root
	min = (_root->left != nullptr) ? lmin : _root->key;
	max = (_root->right != nullptr) ? rmax : _root->key;

	return 1;
}





