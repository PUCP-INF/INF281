//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#ifndef INF281_ARBOLBBG_H
#define INF281_ARBOLBBG_H

#include <iostream>

template <typename T>
class ArbolBBG;

template <typename T>
class NodoArbolBBG {
public:
    explicit NodoArbolBBG(T data);
    ~NodoArbolBBG();
    friend ArbolBBG<T>;
private:
    T data;
    NodoArbolBBG<T> *right;
    NodoArbolBBG<T> *left;
};

template<typename T>
NodoArbolBBG<T>::NodoArbolBBG(T data):
data(data)
{
    left = nullptr;
    right = nullptr;
}

template<typename T>
NodoArbolBBG<T>::~NodoArbolBBG()
{
    delete left;
    delete right;
}

template <typename T>
class ArbolBBG {
public:
    ArbolBBG();
    ~ArbolBBG();

    void insertar(T data);
    void imprimir(std::ostream &out = std::cout) const;
    void eliminar();
    void modificar(int index, double offset);

private:
    NodoArbolBBG<T> *root;

    void inorder_recur(NodoArbolBBG<T> *node, std::ostream &out) const;
};

template<typename T>
ArbolBBG<T>::ArbolBBG()
{
    root = nullptr;
}

template<typename T>
ArbolBBG<T>::~ArbolBBG()
{
    eliminar();
}

template<typename T>
void ArbolBBG<T>::insertar(T data)
{
    NodoArbolBBG<T> *newNodo = new NodoArbolBBG<T>(data),
            *aux = root,
            *father = nullptr;
    while (aux) {
        father = aux;
        if (aux->data <= data) {
            aux = aux->right;
        } else {
            aux = aux->left;
        }
    }
    if (!father) {
        root = newNodo;
    } else {
        if (data < father->data) {
            father->left = newNodo;
        } else {
            father->right = newNodo;
        }
    }
}

template<typename T>
void ArbolBBG<T>::imprimir(std::ostream &out) const
{
    inorder_recur(root, out);
}

template<typename T>
void ArbolBBG<T>::inorder_recur(NodoArbolBBG<T>* node, std::ostream &out) const
{
    if (!node) return;
    inorder_recur(node->left, out);
    out << node->data;
    inorder_recur(node->right, out);
}

template<typename T>
void ArbolBBG<T>::eliminar()
{
    delete root;
    root = nullptr;
}

template<typename T>
void ArbolBBG<T>::modificar(int index, double offset)
{
    NodoArbolBBG<T> *aux = root;
    while (aux) {
        if (aux->data == index) break;
        if (aux->data < index) {
            aux = aux->right;
        } else {
            aux = aux->left;
        }
    }
    if (aux) aux->data += offset;
}

#endif //INF281_ARBOLBBG_H
