/*
 * hash.h
 *
 *  Created on: 20/10/2015
 *      Author: clase
 */

#ifndef HASH_H_
#define HASH_H_

#include <string>
#include <sstream>
#include "exception.h"

template <class Key, class Value>
class HashTable {
private:
	unsigned int (*func) (const Key);
	unsigned int size;
	unsigned int count;
	
	Key *keys;
	Key initialValue;
	Value *values;
	
	long indexOf(const Key) const;
	
public:
	HashTable(unsigned int, Key, unsigned int (*f) (const Key)) throw (OutOfMemory);
	~HashTable();
	bool full() const;
	bool put(Key, Value) throw (Overflow);
	bool contains(const Key) const;
	Value get(const Key) throw (NoSuchElement);
	void clear();
	std::string toString() const;
};

template <class Key, class Value>
HashTable<Key, Value>::HashTable(unsigned int sze, Key init, unsigned int (*f) (const Key)) throw (OutOfMemory) {
  //Inicializar variables con parametros
  size = sze;
  initialValue = init;
  //Asignar la funcion de hash al apuntador func
  func = f;

  //Asegurarse que hay memoria disponible
  keys = new Key[size];
  if(keys == NULL){
    throw OutOfMemory();
  }

  values = new Value[size];
  if(values == NULL){
    throw OutOfMemory();
  }

  //Asignar llave a su valor inicial
  for (int i = 0; i < size; i++){
    keys[i] = init;
  }

  count = 0;
}

template <class Key, class Value>
HashTable<Key, Value>::~HashTable() {
	
}

template <class Key, class Value>
bool HashTable<Key, Value>::full() const {
	if(count == size){
    return true;
  }
  return false;
}

template <class Key, class Value>
long HashTable<Key, Value>::indexOf(const Key k) const {
	int inicio_busqueda = func(k) % size;
  int i = inicio_busqueda;
  do {
    if(keys[i] == k){
      return i;
    }
    i = (i + 1) % size;
  } while (i != inicio_busqueda);
  return -1;
}

template <class Key, class Value>
bool HashTable<Key, Value>::put(Key k, Value v) throw (Overflow) {
  //Si la tabla esta llena, lanzar excepcion
  if(full()){
    throw Overflow();
  }

  //Obtener la posicion en la tabla de la llave k
  int posicion_tabla = indexOf(k);
  // Si la llave ya tiene un indice, actualizar su valor y devolver
  //verdadero
  if(posicion_tabla != -1){
    values[posicion_tabla] = v;
    return true;
  }
  //So la llave no tiene in indice, calcular su indice con la funcion de
  //hash, si está disponible insertar la llavem el valor, aumentar el 
  //Contador y devolver verdadero. si no esta disponible biscar un lugar
  //disponible
  //Obtener el valor de hash
  int valor_hash = func(k) % size;
  int i = valor_hash;

  //Inseta la llave y el valor en la posicion de la tabla de hash
  //pero si esta ocupado , busca un ligar por sondeo lineal
  do {
    if(keys[i] == initialValue){
      keys[i] = k;
      values[i] = v;
      count++;
      return true;
    } 
    i = (i + 1) % size;
  } while (i != valor_hash);
  return false;

}

template <class Key, class Value>
bool HashTable<Key, Value>::contains(const Key k) const {
	return false;
}

template <class Key, class Value>
Value HashTable<Key, Value>::get(const Key k) throw (NoSuchElement) {
	Value v;
	
	return v;
}

template <class Key, class Value>
void HashTable<Key, Value>::clear() {
	
}

template <class Key, class Value>
std::string HashTable<Key, Value>::toString() const {
	std::stringstream aux;
	
	for (unsigned int i = 0; i < size; i++) {
		aux << "[ " << i << ", " << keys[i] << ", " << values[i] << "]\n";
	}
	return aux.str();
}
#endif /* HASH_H_ */
	
