/*
 * recursion.h
 *
 *  Created on: 10/09/2015
 *      Author: pperezm
 */

#ifndef RECURSION_H_
#define RECURSION_H_

#include "exception.h"
#include <iostream>

long sum_seq(int n) {
  long resultado = 0;
  long i = 1;

  while (i <= n){
    resultado = resultado + i;
    i++;
  }
	return resultado;
}

long sum_rec(int n) {
  if(n == 1){
    return 1;
  }
	return n + sum_rec(n - 1);
}

long fact_seq(int n) {
  long resultado = 1;
  for(int i = 1; i <= n; i++){
    resultado = resultado * i; 
  }
	return resultado;
}

long fact_rec(int n) {
  if (n == 0){
    return 1;
  }
	return n * fact_rec(n - 1);
}

long fib_seq(int n) {
	return 0;
}

long fib_rec(int n) {
	return 0;
}

long gcd_seq(long a, long b) {
	return 0;
}

long gcd_rec(long a, long b) {
	return 0;
}

bool find_seq(int arr[], int size, int val) {
	return false;
}

bool find_rec(int arr[], int low, int high, int val) {
	return false;
}

int max_seq(int arr[], int size) {
	return 0;
}

int max_rec(int arr[], int low, int high) {
	return 0;
}

int unimodal_seq(int arr[], int size) {
	return 0;
}

int unimodal_rec(int arr[], int low, int high) {
	return 0;
}

int unimodal_rec(int arr[], int size) {
	return 0;
}

int bs_seq(int arr[], int size, int val) {
	return 0;
}

int bs_aux(int arr[], int low, int high, int val) {
	return 0;
}

int bs_rec(int arr[], int size, int val) {
	return 0;
}
#endif /* RECURSION_H_ */
