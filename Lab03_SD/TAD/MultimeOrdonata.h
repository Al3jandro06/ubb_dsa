#ifndef LAB03_SD_MULTIMEORDONATA_H
#define LAB03_SD_MULTIMEORDONATA_H

#pragma once

template <typename E>
class MultimeOrdonata {
private:
    E* elems;
    int capacity;
    int noElems;
    bool (*comparator)(E, E);
    void resize();
public:
    MultimeOrdonata(bool (*comp)(E, E));
    MultimeOrdonata(const MultimeOrdonata<E>& other);
    void add(E e);
    int search(E e);
    bool ifExists(E e);
    int size();
    E getAt(int position);
    bool remove(E e);
    ~MultimeOrdonata();
};

#include "MultimeOrdonata.tpp"

#endif //LAB03_SD_MULTIMEORDONATA_H