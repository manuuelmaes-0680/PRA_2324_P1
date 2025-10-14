#ifndef LIST_H
#define LIST_H

template <typename T> 
class List {
    public:
	    // Destructor virtual para asegurar que las clases derivadas limpien correctamente
    virtual ~List() {}

    // Inserta el elemento 'e' en la posición 'pos'
    virtual void insert(int pos, T e) = 0;

    // Inserta el elemento 'e' al final de la lista
    virtual void append(T e) = 0;

    // Inserta el elemento 'e' al principio de la lista
    virtual void prepend(T e) = 0;

    // Elimina y devuelve el elemento en la posición 'pos'
    virtual T remove(int pos) = 0;

    // Devuelve el elemento en la posición 'pos'
    virtual T get(int pos) = 0;

    // Devuelve la posición de la primera ocurrencia de 'e', o -1 si no existe
    virtual int search(T e) = 0;

    // Indica si la lista está vacía
    virtual bool empty() = 0;

    // Devuelve el tamaño de la lista
    virtual int size() = 0;
        // ... aquí los métodos virtuales puros
};

#endif
