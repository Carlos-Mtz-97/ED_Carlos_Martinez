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
  long resultado = 1;
  long anterior_1 = resultado;
  long anterior_2 = resultado;
  
  for (int i = 3; i <= n; i++){
    resultado = anterior_1 + anterior_2;
    anterior_2 = anterior_1;
    anterior_1 = resultado;
  }
	return resultado;
}

long fib_rec(int n) {
  if (n == 1 || n == 2){
    return 1;
  }
	return fib_rec(n - 1) + fib_rec(n - 2);
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
  int low = 0;
  int high = size - 1;
  int mid = (high + low) / 2;

  while (low < high){
    mid = (high + low) / 2;
    if (val == arr[mid]){
      return mid;
    }

    if(val < arr[mid]){
      high = mid - 1;
    } else {
      low = mid + 1;
    }

  }
	return low;
}

int bs_aux(int arr[], int low, int high, int val) {
	if(low < high){
    return low
  }

  int mid = (high + low) / 2;
  
  if(val == arr[mid]){
    return mid;
  }

  if(val < arr[mid]){
    return bs_aux(arr, low, mid - 1, val)
  } else { 
    return bs_aux(arr, mid + 1, high, val )
  }
  return 0;
}

int bs_rec(int arr[], int size, int val) {
	return bs_aux(arr,0, size -1,val);
}
#endif /* RECURSION_H_ */
