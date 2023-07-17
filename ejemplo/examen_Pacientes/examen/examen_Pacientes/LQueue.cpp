#include "LQueue.h"

template<typename T>
LQueue<T>::LQueue() : frontNode(nullptr), backNode(nullptr) {}

template<typename T>
void LQueue<T>::Enqueue(T value) {
    Node* newNode = new Node(value);
    if (frontNode == nullptr) {
        // Si la cola está vacía, el nuevo nodo se convierte tanto en el frente como en el final de la cola
        frontNode = newNode;
        backNode = newNode;
    } else {
        backNode->next = newNode;  // El último nodo apunta al nuevo nodo
        backNode = newNode;  // El nuevo nodo se convierte en el nuevo final de la cola
    }
}

template<typename T>
void LQueue<T>::Dequeue() {
    if (frontNode != nullptr) {
        // Guardamos el puntero al nodo que se eliminará
        Node* temp = frontNode;  
        // El siguiente nodo se convierte en el nuevo frente de la cola
        frontNode = frontNode->next;
        // Eliminamos el nodo previo del frente de la cola  
        delete temp;  
    }
}

template<typename T>
T LQueue<T>::Front() {
    if (frontNode != nullptr) {
        // Devuelve el valor almacenado en el frente de la cola
        return frontNode->value;  
    }
    // Lanza una excepción si la cola está vacía
    throw std::runtime_error("Queue esta vacia");  
}

template<typename T>
T LQueue<T>::Back() {
    if (backNode != nullptr) {
        // Devuelve el valor almacenado en el final de la cola
        return backNode->value;  
    }
    // Lanza una excepción si la cola está vacía
    throw std::runtime_error("Queue esta vacia");  
}

template<typename T>
bool LQueue<T>::IsEmpty() {
    // La cola está vacía si el nodo frontal es nulo
    return (frontNode == nullptr);  
}
