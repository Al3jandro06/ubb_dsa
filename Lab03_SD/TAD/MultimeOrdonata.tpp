#include "MultimeOrdonata.h"


template<typename E>
MultimeOrdonata<E>::MultimeOrdonata(bool (*comp)(E, E)) {
    this->capacity = 10;
    this->noElems = 0;
    this->elems = new E[this->capacity];
    this->comparator = comp;
}

template<typename E>
MultimeOrdonata<E>::MultimeOrdonata(const MultimeOrdonata<E> &other) {
    capacity = other.capacity;
    noElems = other.noElems;
    comparator = other.comparator;

    elems = new E[this->capacity];
    for (int i = 0; i < this->noElems; i++) {
        elems[i] = other.elems[i];
    }
}

template<typename E>
void MultimeOrdonata<E>::resize() {
    capacity *= 2;
    E* newElems = new E[capacity];
    for (int i = 0; i < noElems; i++) {
        newElems[i] = elems[i];
    }
    delete[] elems;
    elems = newElems;
}

template<typename E>
void MultimeOrdonata<E>::add(E e) {
    if (ifExists(e))
        return;
    if (noElems == capacity)
        resize();
    int poz = search(e);
    for (int i = noElems; i > poz; i--)
        elems[i] = elems[i - 1];
    elems[poz] = e;
    noElems++;
}

template<typename E>
int MultimeOrdonata<E>::search(E e) {
    int i = 0;
    while (i < noElems && comparator(elems[i], e))
        i++;
    return i;
}

template<typename E>
bool MultimeOrdonata<E>::ifExists(E e) {
    int poz = search(e);
    return (poz < noElems && elems[poz] == e);
}

template<typename E>
int MultimeOrdonata<E>::size() {
    return this->noElems;
}

template<typename E>
E MultimeOrdonata<E>::getAt(int position) {
    return elems[position];
}

template<typename E>
bool MultimeOrdonata<E>::remove(E e) {
    int poz = search(e);
    if (poz >= noElems || elems[poz] != e)
        return false;
    for (int i = poz; i < noElems - 1; i++)
        elems[i] = elems[i + 1];
    noElems--;
    return true;
}

template<typename E>
MultimeOrdonata<E>::~MultimeOrdonata() {
    delete[] this->elems;
}
