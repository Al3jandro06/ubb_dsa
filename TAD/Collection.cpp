//
// Created by alexu on 3/30/2026.
//

#include "Collection.h"

Collection::Collection() {
    this->capacity = 10;
    this->len = 0;
    this->elems = new Pereche[this->capacity];
}

Collection::Collection(const Collection& other) {
    this->capacity = other.capacity;
    this->len = other.len;
    this->elems = new Pereche[this->capacity];
    for (int i=0; i<this->len; i++)
        this->elems[i] = other.elems[i];
}

Collection& Collection::operator=(const Collection& other) {
    if (this != &other) {
        if (this->elems != 0)
            delete[] this->elems;
        this->capacity = other.capacity;
        this->len = other.len;
        this->elems = new Pereche[this->capacity];
        for (int i=0; i<this->len; i++)
            this->elems[i] = other.elems[i];
    }
    return *this;
}

void Collection::add(TElem elem) {
    for (int i=0; i<this->len; i++)
        if (this->elems[i].elem == elem) {
            this->elems[i].frecv++;
            return;
        }
    if (this->len == this->capacity) {
        this->resize();
    }
    this->elems[this->len].elem = elem;
    this->elems[this->len].frecv = 1;
    this->len++;
}

bool Collection::remove(TElem elem) {
    for (int i=0; i<this->len; i++) {
        if (this->elems[i].elem == elem) {
            this->elems[i].frecv--;

            if (this->elems[i].frecv == 0) {
                this->elems[i] = this->elems[this->len - 1];
                this->len--;
            }
            return true;
        }
    }
    return false;
}

bool Collection::search(TElem elem) {
    for (int i=0; i<this->len; i++)
        if (this->elems[i].elem == elem)
            return true;
    return false;
}

int Collection::noOccurrences(TElem elem) {
    for (int i=0; i<this->len; i++)
        if (this->elems[i].elem == elem)
            return this->elems[i].frecv;
    return 0;
}

int Collection::size() {
    int total = 0;
    for (int i=0; i<this->len; i++)
        total += this->elems[i].frecv;
    return total;
}

TElem Collection::getAt(int position) {
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

void Collection::resize() {
    this->capacity *= 2;
    Pereche* newElems = new Pereche[this->capacity];
    for (int i=0; i<this->len; i++)
        newElems[i] = this->elems[i];
    delete[] this->elems;
    this->elems = newElems;
}

Collection::~Collection() {
    delete[] this->elems;
}