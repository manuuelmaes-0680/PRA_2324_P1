#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <iostream>
#include "List.h"
#include "Node.h"  // Incluimos la clase Node<T> para poder usarla

// Declaración de la clase ListLinked<T>
template <typename T>
class ListLinked : public List<T> {
private:
    Node<T>* first;  // Apunta al primer nodo de la lista
    int n;  // Número de elementos en la lista

public:
    // Constructor sin argumentos, inicializando con =
    ListLinked() {
        first = nullptr;  // Inicializamos first a nullptr
        n = 0;            // Inicializamos n a 0
    }

    // Destructor
    ~ListLinked() {
        // Destruimos todos los nodos de la lista
        Node<T>* aux;
        while (first != nullptr) {
            aux = first->next;  // Apuntamos al siguiente nodo
            delete first;  // Eliminamos el nodo actual
            first = aux;  // Actualizamos first para que apunte al siguiente nodo
        }
    }

    // Sobrecarga del operador []
    T operator[](int pos) {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición fuera de rango");
        }

        Node<T>* aux = first;
        for (int i = 0; i < pos; ++i) {
            aux = aux->next;
        }
        return aux->data;  // Retorna el dato del nodo en la posición indicada
    }

    // Sobrecarga del operador <<
    friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list) {
        Node<T>* aux = list.first;
        while (aux != nullptr) {
            out << aux->data << " ";  // Imprime el dato del nodo
            aux = aux->next;  // Avanza al siguiente nodo
        }
        return out;
    }

    // Método para obtener el tamaño de la lista
    int size() const {
        return n;
    }

    // Método para añadir un elemento al final de la lista
    void append(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (first == nullptr) {
            first = newNode;
        } else {
            Node<T>* aux = first;
            while (aux->next != nullptr) {
                aux = aux->next;
            }
            aux->next = newNode;
        }
        ++n;
    }

    // Método para insertar un elemento en una posición dada
    void insert(int pos, T data) {
        if (pos < 0 || pos > n) {
            throw std::out_of_range("Posición fuera de rango");
        }

        Node<T>* newNode = new Node<T>(data);
        if (pos == 0) {
            newNode->next = first;
            first = newNode;
        } else {
            Node<T>* aux = first;
            for (int i = 0; i < pos - 1; ++i) {
                aux = aux->next;
            }
            newNode->next = aux->next;
            aux->next = newNode;
        }
        ++n;
    }
// Cambiar la firma del método remove para devolver el dato de tipo T
T remove(int pos) {
    if (pos < 0 || pos >= n) {
        throw std::out_of_range("Posición fuera de rango");
    }

    Node<T>* aux;
    T removedData;  // Variable para almacenar el dato que se eliminará

    if (pos == 0) {
        aux = first;
        removedData = first->data;  // Guardamos el dato que vamos a eliminar
        first = first->next;
    } else {
        Node<T>* prev = first;
        for (int i = 0; i < pos - 1; ++i) {
            prev = prev->next;
        }
        aux = prev->next;
        removedData = aux->data;  // Guardamos el dato que vamos a eliminar
        prev->next = aux->next;
    }

    delete aux;  // Liberamos la memoria del nodo eliminado
    --n;

    return removedData;  // Retornamos el dato eliminado
}

// Implementación de los métodos que faltaban

void prepend(T e) override {
    Node<T>* newNode = new Node<T>(e);
    newNode->next = first;
    first = newNode;
    ++n;
}

T get(int pos) override {
    if (pos < 0 || pos >= n) {
        throw std::out_of_range("Posición fuera de rango");
    }

    Node<T>* aux = first;
    for (int i = 0; i < pos; ++i) {
        aux = aux->next;
    }
    return aux->data;
}

int search(T e) override {
    Node<T>* aux = first;
    int index = 0;
    while (aux != nullptr) {
        if (aux->data == e) {
            return index;
        }
        aux = aux->next;
        ++index;
    }
    return -1;  // Si no se encuentra, devuelve -1
}

bool empty() override {
    return n == 0;  // Si no hay elementos, la lista está vacía
}

int size() override {
    return n;  // Devuelve el tamaño de la lista
}

};

#endif // LISTLINKED_H

