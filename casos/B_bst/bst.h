
/*
 * bst.h
 *
 *  Created on: 30/10/2015
 *      Author: clase
 */

#ifndef BST_H_
#define BST_H_

#include <string>
#include <sstream>
#include "exception.h"

template <class T> class BST;

template <class T>
class TreeNode {
private:
	T value;
	TreeNode *left, *right;

	TreeNode<T>* succesor();

public:
	TreeNode(T);
	TreeNode(T, TreeNode<T>*, TreeNode<T>*);
	void add(T);
	bool find(T);
	void remove(T);
	void removeChilds();
	void inorder(std::stringstream&) const;
	void preorder(std::stringstream&) const;

	friend class BST<T>;
};

template <class T>
TreeNode<T>::TreeNode(T val) {
  value = val;
  left = NULL;
  right = NULL;
}

template <class T>
TreeNode<T>::TreeNode(T val, TreeNode<T> *le, TreeNode<T> *ri) {
  value = val;
  left = le;
  right = ri;
}

template <class T>
void TreeNode<T>::add(T val) {
  //si val es menor que value
  if (val < value){
    //Si no tiene rama izquierda
    if (left == NULL){
      //Insertamos el nodo del lado izquierdo
      left = new TreeNode(val);
    //Si tiene rama izquierda
    } else {
      //Insertar el nodo en la rama izquierda
      left->add(val);
    }

  //si val es mayor que value
  } else {
    //Si no tiene rama derecha
    if (right == NULL){
      //Insertamos el nodo del lado derecho
      right = new TreeNode(val);
    //Si tiene rama derecha
    }else{
      //Insertar el nodo en la rama derecha
      right->add(val);
    }
  }
}

template <class T>
bool TreeNode<T>::find(T val) {
	//Si val es igual al valor del nodo regresamos verdadero
  if (val == value){
    return true;
  }

  //Si val es menor que el valor del nodo. buscamos del lado izquierdo
  if(val < value && left != NULL){
    return left->find(val);
  }

  //si val es mayor que el valor del nodo, buscamos del lado derecho
  if (val > value && right != NULL){
    return right->find(val);
  }

  //Si no se encuentra regresamos false
  return false;
}

template <class T>
TreeNode<T>* TreeNode<T>::succesor() {
	return 0;
}

template <class T>
void TreeNode<T>::remove(T val) {
}

template <class T>
void TreeNode<T>::removeChilds() {
}

template <class T>
void TreeNode<T>::inorder(std::stringstream &aux) const {
	if (left != 0) {
		left->inorder(aux);
	}
	if (aux.tellp() != 1) {
		aux << " ";
	}
	aux << value;
	if (right != 0) {
		right->inorder(aux);
	}
}

template <class T>
void TreeNode<T>::preorder(std::stringstream &aux) const {
	aux << value;
	if (left != 0) {
		aux << " ";
		left->preorder(aux);
	}
	if (right != 0) {
		aux << " ";
		right->preorder(aux);
	}
}

template <class T>
class BST {
private:
	TreeNode<T> *root;

public:
	BST();
	~BST();
	bool empty() const;
	void add(T);
	bool find(T) const;
	void remove(T);
	void removeAll();
	std::string inorder() const;
	std::string preorder() const;
};

template <class T>
BST<T>::BST() : root(0) {}

template <class T>
BST<T>::~BST() {
	removeAll();
}

template <class T>
bool BST<T>::empty() const {
	return (root == 0);
}

template<class T>
void BST<T>::add(T val) {
  //Si esta vacio
  if (empty()){
    //instetar nuevo nodo en la raiz
    root = new TreeNode<T> (val);
  //Sino agregar nodo sobre la raiz
  } else {
    root->add(val);
  }

}

template <class T>
void BST<T>::remove(T val) {
}

template <class T>
void BST<T>::removeAll() {
}

template <class T>
bool BST<T>::find(T val) const {
  return root->find(val);
}

template <class T>
std::string BST<T>::inorder() const {
	std::stringstream aux;

	aux << "[";
	if (!empty()) {
		root->inorder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
std::string BST<T>::preorder() const {
	std::stringstream aux;

	aux << "[";
	if (!empty()) {
		root->preorder(aux);
	}
	aux << "]";
	return aux.str();
}

#endif /* BST_H_ */
