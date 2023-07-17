#ifndef LQUEUE_H
#define LQUEUE_H

template<typename T>
class LQueue {
private:
    struct Node {
        T value;
        Node* next;
        Node(T val) : value(val), next(nullptr) {}
    };
    // Puntero al nodo frontal de la cola
    Node* frontNode;  
    // Puntero al nodo trasero de la cola
    Node* backNode;  

public:
    // Constructor de la clase LQueue
    LQueue();  
    // Agrega un elemento al final de la cola
    void Enqueue(T value); 
    // Elimina el elemento del frente de la cola 
    void Dequeue(); 
    // Devuelve el elemento del frente de la cola sin eliminarlo 
    T Front();  
    // Devuelve el elemento del final de la cola sin eliminarlo
    T Back(); 
    // Verifica si la cola está vacía 
    bool IsEmpty();  
};

#include "LQueue.cpp"

#endif  
