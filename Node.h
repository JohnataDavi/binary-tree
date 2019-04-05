# ifndef NODE_H
# define NODE_H

template <class T>
class Node
{
private:
    Node *esq, *dir, *ant;
    T key;
public:
    Node(T);
    Node<T>* getEsq();
    Node<T>* getDir();
    T getKey();
    Node<T>* getAnt();
    void setKey(T);
    void setEsq(Node<T>*);
    void setDir(Node<T>*);
    void setAnt(Node<T>*);
};

#endif
