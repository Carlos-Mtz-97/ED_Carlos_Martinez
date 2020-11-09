/*
 * evaltree.h
 *
 *  Created on: 20/10/2015
 *      Author: clase
 */

#ifndef EVALTREE_H_
#define EVALTREE_H_

#include <cctype>
#include <string>

#include <sstream>
#include <queue>
#include <stack>
#include "exception.h"

class EvalTree;

class TreeNode {
private:
	char value;
	TreeNode *left, *right;

	bool isOperator() const;
	bool isVariable() const;
	bool isOperand() const;

public:
	TreeNode(char);
	TreeNode(char, TreeNode*, TreeNode*);
	int depth() const;
	void inorder(std::stringstream&) const;
	void postorder(std::stringstream&) const;
	void preorder(std::stringstream&) const;
	void levelOrder(std::stringstream&) const;
	int howManyLeaves() const;
	char minValue() const;
	bool find(char) const;
	double eval(double x) const;
	TreeNode* derive() const;
	void removeChilds();
	TreeNode* copy() const;
	friend class EvalTree;
};

TreeNode::TreeNode(char c) {
  value = c;
  left = NULL;
  right = NULL;
}

TreeNode::TreeNode(char c, TreeNode* le, TreeNode* ri) {
  value = c;
  left = le;
  right = ri;
}

bool TreeNode::isOperator() const {
  if (value == '+' || value == '-' || value == '*' || value == '/'){
    return true;
  }
	return false;
}

bool TreeNode::isVariable() const {
  if (value == 'x'){
    return true;
  }
	return false;
}

bool TreeNode::isOperand() const {
  if(value >= '0' && value <= '9'){
    return true;
  }
	return false;
}

int TreeNode::depth() const {
  
  //Encontrar la profundidad de la rama izquierda
  int left_depth = -1;    
  if (left != NULL){
    left_depth = left->depth();
  }
  //Encontrar la profundidad de la rama derecha
  int right_depth = -1;    
  if (right != NULL){
    right_depth = right->depth();
  }
  //Regresar la mayor de las 2 profundidades
  int depth = left_depth;
  if(right_depth > left_depth){
    depth = right_depth;
  }
	return depth + 1;
}

void TreeNode::inorder(std::stringstream &aux) const {
  //recorrido in order rama izquierdo
  if(left != NULL){
    left -> inorder(aux);
  }
  //Imprimir valor del nodo
  aux << value<<  " ";

  //recorrido in order rama derecha
  if(right != NULL){
    right -> inorder(aux);
  }
}

void TreeNode::postorder(std::stringstream &aux) const {
	//recorrido in order rama izquierdo
  if(left != NULL){
    left -> postorder(aux);
  }

  //recorrido in order rama derecha
  if(right != NULL){
    right -> postorder(aux);
  }

  //Imprimir valor del nodo
  aux << value<<  " ";
}

void TreeNode::preorder(std::stringstream &aux) const {
	aux << value<<  " ";

  //recorrido in order rama izquierdo
  if(left != NULL){
    left -> preorder(aux);
  }

  //recorrido in order rama derecha
  if(right != NULL){
    right -> preorder(aux);
  }
}

int TreeNode::howManyLeaves() const {
  int left_count = 0;
  int right_count = 0;
  int total_count = 0;

  //Recorrer el lado izquierdo
  if(left!=0){
    left_count = left->howManyLeaves();
  }

  //Recorrer el lado derecho
  if(right!=0){
     right_count = right->howManyLeaves();
  }

  //Sumar hojas del lado derecho e izquierdp
  total_count = left_count + right_count;

  //Imprimir cuenta total
  if( total_count == 0){
    return 1;
  }
	return total_count;
}

char TreeNode::minValue() const {

  int left_min = '9';
  int right_min = '9';
  int min = '9';

  if(isOperand()){
    min = value;
  }
  else if (isOperator()){
    //Recorrer el lado izquierdo
    if(left!=0){
      left_min = left->minValue();
    }

    //Recorrer el lado derecho
    if(right!=0){
      right_min = right->minValue();
    }

    //Comparar los minimos 
    if(left_min < right_min){
      min = left_min;
    }
    else{
      min = right_min;
    }
  }
  return min;  
  
}

bool TreeNode::find(char val) const { 
  bool found = false;
  if (value == val){
    return true;
  }
  //Recorrer el lado izquierdo
  if(left != 0){
    //verificar numero
    if(found || left->find(val)){
      found = true;
    } else {
      found = false;
    }
  }

  //Recorrer el lado derecho
  if(right != 0){
    //Verificar numero
    if(found || right->find(val)){
      found = true;
    } else {
      found = false;
    }
  }
  return found;
}

double TreeNode::eval(double x) const {
	return 0;
}

void TreeNode::removeChilds() {
}

TreeNode* TreeNode::derive() const {
	return 0;
}

TreeNode* TreeNode::copy() const {
	return 0;
}

class EvalTree {
private:
	TreeNode *root;

	std::queue<std::string> tokenize(std::string);

public:
	EvalTree();
	EvalTree(std::string) throw (IllegalAction);
	~EvalTree();
	bool empty() const;
	int height() const;
	std::string inorder() const;
	std::string postorder() const;
	std::string preorder() const;
	std::string levelOrder() const;
	int howManyLeaves() const;
	char minValue() const throw (IllegalAction);
	bool find(char) const;
	double eval(double) const throw (IllegalAction) ;
	EvalTree* derive() const;
	void removeAll();
	bool isFull() const;
	int internalNodes() const;
	bool isPerfect() const;
	bool isDegenerate() const;
};

EvalTree::EvalTree() {
}

std::queue<std::string> EvalTree::tokenize(std::string str) {
	int i = 0;
	int length = str.size();
	std::string aux;
	std::queue<std::string> result;

	while (i < length) {
		if (isdigit(str[i])) {
			aux.clear();
			do {
				aux += str[i];
				i++;
			} while(isdigit(str[i]));
			result.push(aux);
		} else if (isspace(str[i])) {
			i++;
		} else {
			aux.clear();
			aux += str[i];
			result.push(aux);
			i++;
		}
	}
	return result;
}

EvalTree::EvalTree(std::string str) throw (IllegalAction) {
	root = 0;
	std::stack<TreeNode*> s;
	std::queue<std::string> tokens = tokenize(str);
	std::string aux;
	TreeNode *left, *right, *newNode;

	while (!tokens.empty()) {
		aux = tokens.front(); tokens.pop();
		if (aux == "+" || aux == "-" || aux == "*" || aux == "/") {
			if (s.empty()) {
				throw IllegalAction();
			}
			left = s.top(); s.pop();
			if (s.empty()) {
				throw IllegalAction();
			}
			right = s.top(); s.pop();
			newNode = new TreeNode(aux[0], left, right);
			s.push(newNode);
		} else if (aux[0] == 'x' || isdigit(aux[0])) {
			newNode = new TreeNode(aux[0]);
			s.push(newNode);
		}
	}
	newNode = s.top(); s.pop();
	if (!s.empty()) {
		throw IllegalAction();
	}
	root = newNode;
}

EvalTree::~EvalTree() {
}

bool EvalTree::empty() const {
  if(root == NULL){
    return true;
  }
  return false;
}

int EvalTree::height() const {
	if(empty()){
    return 0;
  }
  return root->depth() + 1;
}

std::string EvalTree::inorder() const {
	std::stringstream aux;
  root->inorder(aux);
	return aux.str();
}

std::string EvalTree::preorder() const {
	std::stringstream aux;
  root->preorder(aux);
	return aux.str();
}

std::string EvalTree::postorder() const {
	std::stringstream aux;
  root->postorder(aux);
	return aux.str();
}

std::string EvalTree::levelOrder() const {
	std::stringstream aux;
  //Nevecitamos una fila para hacer el recorrido por niveles
  std::queue<TreeNode*> q;

  //Meter a la fila la raiz
  TreeNode * node = root;
  q.push(node);
  //Mientras la fila no este vacia
  while(!q.empty()){
    //Imprimir el frente de la fila
    node = q.front();
    aux << node->value << " ";
    
    //Sacar el elemento de la fila
    q.pop();
    
    //Si tiene hijo izquierdo, meter el hijo izq a la fila
    if(node->left != 0){
      q.push(node->left);
    }

    //Si tiene hijo derecho, meter el hijo der a la fila
    if(node->right != 0){
      q.push(node->right);
    }
  }

	return aux.str();
}

int EvalTree::howManyLeaves() const {
  if(empty()) {
    return 0;
  }
	return root->howManyLeaves();
}

char EvalTree::minValue() const throw (IllegalAction) {
	if(empty()){
     throw IllegalAction();
  }
  return root->minValue();
}

bool EvalTree::find(char c) const {
	return root->find(c);
}

double EvalTree::eval(double x) const throw (IllegalAction) {
	return 0.0;
}

EvalTree* EvalTree::derive() const {
	return 0;
}

void EvalTree::removeAll() {
}
#endif /* EVALTREE_H_ */
