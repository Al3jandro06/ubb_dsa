#include "Collection.h"


template<typename E>
Collection<E>::Collection() {
    capacity = 10;
    len = 0;
    elems = new Pereche<E>[capacity];
}

template<typename E>
Collection<E>::Collection(const Collection<E>& other) {
    capacity = other.capacity;
    len = other.len;
    elems = new Pereche<E>[capacity];
    for (int i = 0; i < len; i++) {
        elems[i] = other.elems[i];
    }
}

template<typename E>
Collection<E>& Collection<E>::operator=(const Collection<E>& other) {
    if (this != &other) {
        if (this->elems != 0)
            delete[] this->elems;
        this->capacity = other.capacity;
        this->len = other.len;
        this->elems = new Pereche<E>[this->capacity];
        for (int i=0; i<this->len; i++)
            this->elems[i] = other.elems[i];
    }
    return *this;
}

template<typename E>
void Collection<E>::add(E elem) {
    for (int i = 0; i < len; i++) {
        if (elems[i].elem == elem) {
            elems[i].frecv++;
            return;
        }
    }
    if (len == capacity)
        resize();
    elems[len].elem = elem;
    elems[len].frecv = 1;
    len++;
}

template<typename E>
bool Collection<E>::remove(E elem) {
    for (int i = 0; i < len; i++) {
        if (elems[i].elem == elem) {
            elems[i].frecv--;

            if (elems[i].frecv == 0) {
                elems[i] = elems[len - 1];
                len--;
            }
            return true;
        }
    }
    return false;
}

template<typename E>
bool Collection<E>::search(E elem) {
    for (int i = 0; i < len; i++)
        if (elems[i].elem == elem)
            return true;
    return false;
}

template<typename E>
int Collection<E>::nrOccurrences(E elem) {
    for (int i = 0; i < len; i++)
        if (elems[i].elem == elem)
            return elems[i].frecv;
    return 0;
}

template<typename E>
int Collection<E>::size() {
    int total = 0;
    for (int i = 0; i < len; i++)
        total += elems[i].frecv;
    return total;
}

template<typename E>
E Collection<E>::getAt(int position) {
    if (position < 0 || position >= this->size())
        return -1;

    int count = 0;
    for (int i=0; i<this->len; i++)
        for (int j=0; j<this->elems[i].frecv; j++) {
            if (count == position)
                return this->elems[i].elem;
            count++;
        }
    return -1;
}


template<typename E>
void Collection<E>::resize() {
    this->capacity *= 2;
    Pereche<E>* newElems = new Pereche<E>[this->capacity];
    for (int i=0; i<this->len; i++)
        newElems[i] = this->elems[i];
    delete[] this->elems;
    this->elems = newElems;
}

template<typename E>
Collection<E>::~Collection() {
    delete[] this->elems;
}
