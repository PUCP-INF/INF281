//
// NOMBRE: TORO VERA CARLOS SANTOS
// CODIGO: 20171878
//

#ifndef INF281_PRIORITYQUEUE_H
#define INF281_PRIORITYQUEUE_H

#include <iostream>

template <typename T>
class PriorityQueue;

template <typename T>
class NodoPQ {
public:
    explicit NodoPQ(T dato);
    ~NodoPQ();

    friend PriorityQueue<T>;

private:
    T dato;
    NodoPQ<T> *next;
    NodoPQ<T> *prev;
};

template<typename T>
NodoPQ<T>::NodoPQ(T dato):
dato(dato)
{
    next = nullptr;
    prev = nullptr;
}

template<typename T>
NodoPQ<T>::~NodoPQ()
{
    delete next;
}

template <typename T>
class PriorityQueue {
public:
    PriorityQueue();
    ~PriorityQueue();

    void prueba();
    void encolar(T dato);
    void desencolar(NodoPQ<T> *&node);
    bool empty();
private:
    NodoPQ<T> *inicio;
    NodoPQ<T> *fin;
};

template<typename T>
PriorityQueue<T>::PriorityQueue()
{
    inicio = nullptr;
    fin = nullptr;
}

template<typename T>
PriorityQueue<T>::~PriorityQueue()
{
    delete inicio;
}

template<typename T>
void PriorityQueue<T>::prueba()
{
    NodoPQ<T> *aux = inicio;
    while (aux) {
        std::cout << aux->dato;
        aux = aux->next;
    }
}

template<typename T>
void PriorityQueue<T>::encolar(T dato)
{
    NodoPQ<T> *newNode = new NodoPQ<T>(dato);
    if (empty()) {
        fin = newNode;
        inicio = newNode;
        return;
    }
    NodoPQ<T> *aux = fin, *father = nullptr;
    while (aux) {
        if ((aux->dato - dato) >= 0) break;
        father = aux;
        aux = aux->prev;
    }
    if (!aux) {
        newNode->next = father;
        father->prev = newNode;
        inicio = newNode;
    } else if (!father) {
        newNode->prev = aux;
        aux->next = newNode;
        fin = newNode;
    } else {
        newNode->next = father;
        newNode->prev = aux;
        aux->next = newNode;
        father->prev = newNode;
    }
}

template<typename T>
void PriorityQueue<T>::desencolar(NodoPQ<T> *&node)
{
    if (empty()) node = nullptr;
    node = inicio;
    inicio = inicio->next;
    if (inicio) inicio->prev = nullptr;
}

template<typename T>
bool PriorityQueue<T>::empty()
{
    return inicio==nullptr && fin==nullptr;
}

#endif //INF281_PRIORITYQUEUE_H
