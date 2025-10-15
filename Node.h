#ifndef NODE_H
#define NODE_H

#include <ostream>  // Necesario para std::ostream

using namespace std;  // Para no tener que escribir std:: cada vez

// Definición de la clase Node<T>
template <typename T>
class Node {
public:
    T data;          // Dato almacenado en el nodo
    Node<T>* next;   // Puntero al siguiente nodo (nullptr si es el último)

    // Constructor
    Node(T data, Node<T>* next = nullptr) {
        this->data = data;
        this->next = next;
    }

    // Sobrecarga del operador << como función amiga
    friend ostream& operator<<(ostream& out, const Node<T>& node) {
        out << node.data;  // Solo imprimimos el dato
        return out;
    }
};

#endif // NODE_H

