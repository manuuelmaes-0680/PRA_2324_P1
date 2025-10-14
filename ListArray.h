#ifndef LISTARRAY_H
#define LISTARRAY_H

#include <ostream>
#include "List.h"

template <typename T>
class ListArray : public List<T> {
private:
    T* arr;  // Puntero al array de tipo T
    int max;  // Tamaño máximo actual del array
    int n;  // Número de elementos actuales en la lista
    static const int MINSIZE = 2;  // Tamaño mínimo del array
    void resize(int new_size);

public:
    // Constructor sin argumentos
    ListArray();

    // Destructor
    ~ListArray();

    // Métodos heredados de List<T> que deben ser implementados
    void insert(int pos, T e) override;
    void append(T e) override;
    void prepend(T e) override;
    T remove(int pos) override;
    T get(int pos) override;
    int search(T e) override;
    bool empty() override;
    int size() override;

    // Sobrecarga del operador []
    T operator[](int pos);

    // Sobrecarga del operador <<
    friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list) {
        out << "[";
        for (int i = 0; i < list.n; ++i) {
            out << list.arr[i];
            if (i < list.n - 1) {
                out << ", ";
            }
        }
        out << "]";
        return out;
    }
};

// **Implementación de la clase ListArray<T>**

template <typename T>
ListArray<T>::ListArray() : arr(new T[MINSIZE]), max(MINSIZE), n(0) {}

template <typename T>
ListArray<T>::~ListArray() {
    delete[] arr;  // Liberar la memoria del array cuando la lista sea destruida
}

template <typename T>
void ListArray<T>::insert(int pos, T e) {
    if (pos < 0 || pos > n) {
        throw std::out_of_range("Posición fuera de rango");
    }
    if (n == max) {
        resize(max * 2);  // Si no hay espacio, redimensionar
    }
    for (int i = n; i > pos; --i) {
        arr[i] = arr[i - 1];  // Desplazar los elementos hacia la derecha
    }
    arr[pos] = e;
    n++;
}

template <typename T>
void ListArray<T>::append(T e) {
    if (n == max) {
        resize(max * 2);  // Redimensionar si es necesario
    }
    arr[n++] = e;
}

template <typename T>
void ListArray<T>::prepend(T e) {
    insert(0, e);  // Simplemente insertar al principio
}

template <typename T>
T ListArray<T>::remove(int pos) {
    if (pos < 0 || pos >= n) {
        throw std::out_of_range("Posición fuera de rango");
    }
    T removedElement = arr[pos];
    for (int i = pos; i < n - 1; ++i) {
        arr[i] = arr[i + 1];  // Desplazar los elementos hacia la izquierda
    }
    n--;
    if (n <= max / 4) {
        resize(max / 2);  // Reducir tamaño si la lista está muy vacía
    }
    return removedElement;
}

template <typename T>
T ListArray<T>::get(int pos) {
    if (pos < 0 || pos >= n) {
        throw std::out_of_range("Posición fuera de rango");
    }
    return arr[pos];
}

template <typename T>
int ListArray<T>::search(T e) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] == e) {
            return i;
        }
    }
    return -1;  // Si no se encuentra el elemento
}

template <typename T>
bool ListArray<T>::empty() {
    return n == 0;  // La lista está vacía si n es 0
}

template <typename T>
int ListArray<T>::size() {
    return n;  // El tamaño de la lista es el número de elementos actuales
}

template <typename T>
T ListArray<T>::operator[](int pos) {
    if (pos < 0 || pos >= n) {
        throw std::out_of_range("Índice fuera de rango");
    }
    return arr[pos];
}

template <typename T>
void ListArray<T>::resize(int new_size) {
    T* newArr = new T[new_size];  // Crear un nuevo array con el tamaño nuevo
    for (int i = 0; i < n; ++i) {
        newArr[i] = arr[i];  // Copiar los elementos existentes al nuevo array
    }
    delete[] arr;  // Liberar el array antiguo
    arr = newArr;  // Hacer que arr apunte al nuevo array
    max = new_size;  // Actualizar el tamaño máximo
}

#endif // LISTARRAY_H

