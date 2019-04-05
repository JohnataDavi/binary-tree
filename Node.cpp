#include <iostream>
#include <string>
#include <math.h>
#include "Node.h"

template class Node <int>;
template class Node <float>;
template class Node <double>;
template class Node <char>;
//template class Node <string>;

template <class T> Node<T>::Node(T key)
{
    this->key = key;
    this->ant = this->esq = this->dir = NULL;
}

template <class T> T Node<T>::getKey(){ return key;}

template <class T> Node<T>* Node<T>::getEsq(){ return esq;}

template <class T> Node<T>* Node<T>::getDir(){ return dir;}

template <class T> Node<T>* Node<T>::getAnt(){ return ant;}

template <class T> void Node<T>::setKey(T newKey){ key = newKey;}

template <class T> void Node<T>::setEsq(Node<T>* node){ esq = node;}

template <class T> void Node<T>::setDir(Node<T>* node){ dir = node;}

template <class T> void Node<T>::setAnt(Node<T>* node){ ant = node;}


