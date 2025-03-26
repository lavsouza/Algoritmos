/*
 * binarytree.h
 *
 *  Created on: 30 de out de 2017
 *      Author: ramide
 */

#ifndef BST_H_
#define BST_H_

#include <algorithm> // max

using namespace std;

#define ASSERT(X, E) if(!(X)) throw (std::runtime_error(E));

class BinaryTree {
protected:
	struct Node {
		int key;
		int height; // altura da árvore em níveis
		Node * left;
		Node * right;
		explicit Node(int key) : key(key), height(1), left(nullptr), right(nullptr) {}
	};


	// Pega a altura. Simplifica código no caso de subárvore vazia (nullptr)
	static int H(Node * node) { return (node != nullptr)?node->height:0; }

	// Atualiza a altura de um nó da árvore. Assume que a altura das subárvore está correta.
	static void updateH(Node * node) { node->height = max(H(node->left), H(node->right)) + 1; }

	Node * root;

public:
	BinaryTree() {
		root = nullptr;
	}

	virtual ~BinaryTree() {
		deleteTree(root);
	}

	void insert(int key) {
		root = insert(root, key);
		ASSERT(validate(), "inser(): invalid tree!");
	}

	void remove(int key) {
		root = remove(root, key);
		ASSERT(validate(), "remove(): invalid tree!");
	}

	bool search(int key) {
		return search(root, key) != nullptr;
	}

	int  predecessor(int key) {
		Node * node = nullptr;
		predecessor(root, node, key);
		return (node != nullptr)?node->key:-1;
	}

	int  successor(int key) {
		Node * node = nullptr;
		successor(root, node, key);
		return (node != nullptr)?node->key:-1;
	}

	int  validate() {
		int min, max;
		return validate(root, min, max);
	}

	void show() {
		show(root);
	}


protected:
	void deleteTree(Node * node) {
		if (node == nullptr) return;
		deleteTree(node->left);
		deleteTree(node->right);
		delete node;
	}

	virtual Node * insert(Node * _root, int key);
	virtual Node * remove(Node * _root, int key);
	virtual Node * removeMax(Node * _root, int & max);
	virtual Node * search(Node * _root, int key);
	virtual void predecessor(Node * _root, Node * & pred, int key);
	virtual void successor(Node * _root, Node * & succ, int key);

	virtual void   show(Node * _root);
	virtual int    validate(Node * _root, int &min, int &max);
};



#endif /* BST_H_ */
