/*
 * tree.h
 *
 *  Created on: 20/10/2015
 *      Author: clase
 */
 
#ifndef TREE_H_
#define TREE_H_

#include <string>
#include <sstream>
#include "exception.h"

class SimpleTree;

class TreeNode {
private:
	int value;
	TreeNode *left, *right;
	
	int depth() const;
	void removeChilds();
	bool isLeaf() const;
	
public:
	TreeNode(int);
	TreeNode(int, TreeNode*, TreeNode*);
	
	bool isFull() const;
	int internalNodes() const;
	bool isPerfect() const;
	bool isDegenerate() const;
	
	friend class SimpleTree;
};

TreeNode::TreeNode(int val) : value(val), left(0), right(0) {}

TreeNode::TreeNode(int val, TreeNode* le, TreeNode* ri)
	: value(val), left(le), right(ri) {}

void TreeNode::removeChilds() {
	if (left != 0) {
		left->removeChilds();
		delete left;
		left = 0;
	}
	if (right != 0) {
		right->removeChilds();
		delete right;
		right = 0;
	}
}

bool TreeNode::isFull() const {
	//Si está vacio
  if(left == NULL && right == NULL){
    return true;
  }

  //Si tiene hijo izquierdo y está lleno y tiene  hijo derecho u está lleno
  // entonces está lleno
  if(left != NULL && right != NULL
    && left->isFull() && right->isFull() ){
    return true;
  }

  //De lo contrario devolver falso
  return false;
}

int TreeNode::internalNodes() const {
  //Si es hoja regresa 0
  if(isLeaf()){
    return 0;
  }
  int result = 1;
  //Si tiene un hijo, regresa los nodos internos del hijo
  if(left != NULL){
    result = result + left->internalNodes();
  }

  if(right != NULL){
    result = result + right->internalNodes();
  }
	return result;
}

int TreeNode::depth() const {
	int le = -1;
	int ri = -1;
	int de = -1;

	if (left != 0) {
		le = left->depth();
	}
	if (right != 0) {
		ri = right->depth();
	}
	de = (le > ri)? le : ri;
	return (de + 1);
}

bool TreeNode::isPerfect() const {
  int le, ri;
	
	//Si está vacio
  if(left == NULL && right == NULL){
    return true;
  }
	//Verificar que tenga ramas y obtener profuncidad de cada rama
	if (left != NULL && right != NULL) {
		le = left->depth();
		ri = right->depth();
		if (le == ri){
      return true;
    }
	}	
  return false;
}

bool TreeNode::isLeaf() const {
	return (left == 0 && right == 0);
}


bool TreeNode::isDegenerate() const {
	return false;
}

class SimpleTree {
private:
	TreeNode *root;
	void caseOne();
	void caseTwo();
	void caseThree();
	void caseFour();

public:
	SimpleTree(int);
	~SimpleTree();
	bool empty() const;
	bool isFull() const;
	int internalNodes() const;
	bool isPerfect() const;
	bool isDegenerate() const;
};

SimpleTree::SimpleTree(int option) {
	switch (option) {
		case  1: caseOne(); break;
		case  2: caseTwo(); break;
		case  3: caseThree(); break;
		default: caseFour(); break;
	}
}

void SimpleTree::caseOne() {
	TreeNode *a, *b, *c, *d;
	
	a = new TreeNode(4);
	b = new TreeNode(5);
	c = new TreeNode(2, a, b);
	
	a = new TreeNode(6);
	b = new TreeNode(7);
	d = new TreeNode(3, a, b);
	
	root = new TreeNode(1, c, d);
}

void SimpleTree::caseTwo() {
	TreeNode *a, *b, *c, *d, *e;
	
	a = new TreeNode(8);
	b = new TreeNode(9);
	c = new TreeNode(4, a, b);
	
	a = new TreeNode(10);
	b = new TreeNode(11);
	d = new TreeNode(5, a, b);
	
	e = new TreeNode(2, c, d);
	
	a = new TreeNode(6);
	b = new TreeNode(7);
	c = new TreeNode(3, a, b);
	
	root = new TreeNode(1, e, c);
}	

void SimpleTree::caseThree() {
	TreeNode *a, *b, *c;
	
	a = new TreeNode(6);
	
	b = new TreeNode(5, a, 0);
	
	c = new TreeNode(4, 0, b);
	
	a = new TreeNode(3, c, 0);
	
	b = new TreeNode(2, 0, a);
	
	root = new TreeNode(1, b, 0);
}

void SimpleTree::caseFour() {
	root = new TreeNode(1);
}

SimpleTree::~SimpleTree() {
	if (root != 0) {
		root->removeChilds();
	}
	delete root;
	root = 0;
}

bool SimpleTree::empty() const {
	return (root == 0);
}

bool SimpleTree::isFull() const {
	if (!empty()) {
		return root->isFull();
	}
	return false;
}

int SimpleTree::internalNodes() const {
	if (!empty()) {
		return root->internalNodes();
	}
	return 0;
}

bool SimpleTree::isPerfect() const {
	if (!empty()) {
		return root->isPerfect();
	}
	return false;
}

bool SimpleTree::isDegenerate() const {
	if (!empty()) {
		return root->isDegenerate();
	}
	return false;
}

#endif /* EVALTREE_H_ */
