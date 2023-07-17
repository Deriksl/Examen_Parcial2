#ifndef LSTACK_H
#define LSTACK_H

template<typename T>
class LStack {
private:
    struct Node {
        T value;
        Node* next;
        Node(T val) : value(val), next(nullptr) {}
    };
    // Puntero al nodo superior de la pila
    Node* topNode;  

public:
    // Constructor de la clase LStack
    LStack();  
    // Agrega un elemento al tope de la pila
    void Push(T value);  
    // Elimina el elemento del tope de la pila
    void Pop();  
    // Devuelve el elemento en el tope de la pila sin eliminarlo
    T Top();  
};

#include "LStack.cpp"

#endif 

