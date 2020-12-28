//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#ifndef INF281_ARBOLBBG_H
#define INF281_ARBOLBBG_H

#include <iostream>

using namespace std;

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
    void imprimir();
    void eliminar();
    void modificar(int index, float offset);

private:
    NodoArbolBBG<T> *root;

    void inorder_recur(NodoArbolBBG<T> *node);
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
        if (data < aux->data) {
            aux = aux->left;
        } else {
            aux = aux->right;
        }
    }
    if (!father) {
        root = newNodo;
    } else {
        if (data <= father->data) {
            father->left = newNodo;
        } else {
            father->right = newNodo;
        }
    }
}

template<typename T>
void ArbolBBG<T>::imprimir()
{
    inorder_recur(root);
}

template<typename T>
void ArbolBBG<T>::inorder_recur(NodoArbolBBG<T>* node)
{
    if (!node) return;
    inorder_recur(node->left);
    cout << node->data << endl;
    inorder_recur(node->right);
}

template<typename T>
void ArbolBBG<T>::eliminar()
{
    delete root;
    root = nullptr;
}

template<typename T>
void ArbolBBG<T>::modificar(int index, float offset)
{
    NodoArbolBBG<T> *aux = root;
    while (aux) {
        if (aux->data == index) break;
        if (index < aux->data) {
            aux = aux->left;
        } else {
            aux = aux->right;
        }
    }
    if (aux) aux->data += offset;
}

#endif //INF281_ARBOLBBG_H
