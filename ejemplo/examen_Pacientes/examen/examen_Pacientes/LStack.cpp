#include "LStack.h"

template<typename T>
LStack<T>::LStack() : topNode(nullptr) {}

template<typename T>
void LStack<T>::Push(T value) {
    Node* newNode = new Node(value);
    // El nuevo nodo apunta al nodo anterior del tope
    newNode->next = topNode;  
    // El nuevo nodo se convierte en el nuevo tope de la pila
    topNode = newNode;  
}

template<typename T>
void LStack<T>::Pop() {
    if (topNode != nullptr) {
        // Guardamos el puntero al nodo que se eliminará
        Node* temp = topNode;  
        // El siguiente nodo se convierte en el nuevo tope de la pila
        topNode = topNode->next; 
        // Eliminamos el nodo previo del tope de la pila 
        delete temp;  
    }
}

template<typename T>
T LStack<T>::Top() {
    if (topNode != nullptr) {
        // Devuelve el valor almacenado en el tope de la pila
        return topNode->value;  
    }
    // Lanza una excepción si la pila está vacía
    throw std::runtime_error("Stack esta vacia");  
}
