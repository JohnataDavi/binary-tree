# ifndef TREE_H
# define TREE_H
#include "Node.h"

template <class T>
class Tree{
private:
    Node<T> *root;
    void inserir(Node<T>*, T);
    void printGivenLevel(Node<T>*, T);
    Node<T>* maxMin(Node<T>*);
public:
    Tree();
    void inicializa();
    void setRaiz(Node<T>*);
    Node<T>* getRaiz();
    void inserir(T);
    void imprime(Node<T>*, int);
    void emOrdem(Node<T>*);
    bool searchKey(Node<T>*, T);
    Node<T>* deleteNode(Node<T>*, T);
    int height(Node<T>*);
    void printLevelOrder(Node<T>*);
    void printLargura();
};

#endif
