#ifndef LAB03_SD_COLLECTION_H
#define LAB03_SD_COLLECTION_H

#pragma once

template <typename E>
struct Pereche {
    E elem;
    int frecv;
};

template <typename E>
class Collection {
private:
    Pereche<E>* elems;
    int len;
    int capacity;
    void resize();
public:
    Collection();
    Collection(const Collection<E>& other);
    Collection<E>& operator=(const Collection<E>& other);
    void add(E elem);
    bool remove(E elem);
    bool search(E elem);
    int nrOccurrences(E elem);
    int size();
    E getAt(int position);
    ~Collection();
};

#include "Collection.tpp"

#endif //LAB03_SD_COLLECTION_H
