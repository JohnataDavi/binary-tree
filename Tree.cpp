#include <iostream>
#include <queue>
#include <list>
#include <cstddef>
#include <typeinfo>
#include <climits>
#include <cfloat>
#include <string>
#include "Tree.h"

using namespace std;

template class Tree <int>;
template class Tree <float>;
template class Tree <double>;
template class Tree <char>;
//template class Tree <string>;

template <class T> Tree<T>::Tree()
{
    inicializa();
}

template <class T> void Tree<T>::inicializa()
{
    root = NULL;
}

template <class T> void Tree<T>::printLargura()
{
    if(this->getRaiz())
    {
        queue < Node<T>* > q;
        q.push(this->getRaiz());
        Node<T> *node = NULL, *last = NULL;
        bool flag = true;
        while (!q.empty())
        {
            node = q.front();

            if(node->getEsq())
                q.push(node->getEsq());
            if(node->getDir())
                q.push(node->getDir());

            cout << node->getKey() << " ";

            if(node == this->getRaiz())
                cout << endl;
            else if (node == last)
            {
                cout << endl;
                flag = true;
            }
            q.pop();
            if(flag)
            {
                flag = false;
                last = q.back();
            }
        }
    }
}

template <class T> void Tree<T>::inserir(T key)
{
    if(this->getRaiz() == NULL){
        Node<T> *root = new Node<T>(key);
        this->setRaiz(root);
    }
    else if(this->getRaiz()->getKey() == SCHAR_MAX ||
            this->getRaiz()->getKey() == DBL_MAX ||
            this->getRaiz()->getKey() == FLT_MAX ||
            this->getRaiz()->getKey() == INT_MAX)
        this->getRaiz()->setKey(key);
    else
        inserir(this->getRaiz(), key);
}

template <class T> void Tree<T>::inserir(Node<T> *node, T key)
{
    if(key < node->getKey())
    {
        if(node->getEsq() == NULL)
        {
            Node<T> *new_node = new Node<T>(key);
            new_node->setAnt(node);
            node->setEsq(new_node);
        }
        else
            inserir(node->getEsq(), key);
    }
    else if(key > node->getKey())
    {
        if(node->getDir() == NULL)
        {
            Node<T> *new_node = new Node<T>(key);
            new_node->setAnt(node);
            node->setDir(new_node);
        }
        else
            inserir(node->getDir(), key);
    }
}

template <class T> bool Tree<T>::searchKey(Node<T> *node, T key)
{
    if(node)
    {
        if(key == node->getKey())
            return true;
        else if(key > node->getKey())
            searchKey(node->getDir(), key);
        else
            searchKey(node->getEsq(), key);
    }
    else
        return false;
}

template <class T> void Tree<T>::imprime(Node<T> *node, int n)
{
    if(node)
    {
        int i;
        imprime(node->getDir(), n+1);
        for(i = 0; i < n; i++)
            cout << "    ";
        cout << node->getKey() << endl;
        imprime(node->getEsq(), n+1);
    }
}

template <class T> void Tree<T>::emOrdem(Node<T> *node)
{
    if(node)
    {
        emOrdem(node->getEsq());
        cout << node->getKey() << " ";
        emOrdem(node->getDir());
    }
}

template <class T> void Tree<T>::printLevelOrder(Node<T> *root)
{
    int h = height(root) + 1, i;
    for (i = 1; i <= h; i++)
    {
        printGivenLevel(root, i);
        cout << endl;
    }
}

template <class T> void Tree<T>::printGivenLevel(Node<T> *root, T level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->getKey() << " ";
    else if (level > 1)
    {
        printGivenLevel(root->getEsq(), level - 1);
        printGivenLevel(root->getDir(), level - 1);
    }
}

template <class T> Node<T>* Tree<T>::maxMin(Node<T>* no)
{
    /*
       if(no->getDir() != NULL)
           return maxMin(no->getDir());
       else {
           Node<T> *aux = no;
           if(no->getEsq() != NULL)
               no = no->getEsq();
           else
               no = NULL;
           return aux;
       }
       */
    if(no==NULL)
        return NULL;

    while(no->getDir() != NULL)
    {
        no = no->getDir();
    }
    return no;
}

template <class T> Node<T>* Tree<T>::deleteNode(Node<T> *a, T key)
{
    if (a)
    {
        bool ehraiz = false;
        if(key > a->getKey())
            a->setDir(deleteNode(a->getDir(), key));
        else if(key < a->getKey())
            a->setEsq(deleteNode(a->getEsq(), key));
        else
        {
            if(a->getEsq()==NULL && a->getDir()==NULL)
            {
                if(this->getRaiz() == a)
                    this->setRaiz(NULL);
                a = NULL;
                delete a;
            }
            else if(a->getDir()==NULL)
            {
                if(this->getRaiz() == a)
                    ehraiz = true;
                Node<T> *aux = a;
                a = a->getEsq();
                if(ehraiz)
                    this->setRaiz(a);
                aux = NULL;
                delete aux;
            }
            else if(a->getEsq()==NULL)
            {
                if(this->getRaiz() == a)
                    ehraiz = true;
                Node<T> *aux = a;
                a = a->getDir();
                if(ehraiz)
                    this->setRaiz(a);
                aux = NULL;
                delete aux;
            }
            else
            {
                Node<T>* aux = maxMin(a->getEsq());
                a->setKey(aux->getKey());
                aux = NULL;
                a->setEsq(deleteNode(a->getEsq(), a->getKey()));
            }
        }
        return a;
    }
    else return a;
}

template <class T> int Tree<T>::height(Node<T> *node)
{
    if(node)
    {
        int he = height(node->getEsq());
        int hd = height(node->getDir());
        if(he < hd)
            return hd + 1;
        else
            return he + 1;
    }
    else   //fim
        return -1;
}

template <class T> Node<T>* Tree<T>::getRaiz()
{
    return this->root;
}

template <class T> void Tree<T>::setRaiz(Node<T>* node)
{
    this->root = node;
}


