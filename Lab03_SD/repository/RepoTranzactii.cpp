#include "RepoTranzactii.h"

RepoTranzactii::RepoTranzactii() {
    this->capacity = 10;
    this->size = 0;
    this->tranzactii = new Tranzactie[this->capacity];
}

void RepoTranzactii::resize() {
    this->capacity *= 2;
    Tranzactie* newArr = new Tranzactie[this->capacity];
    for (int i = 0; i < this->size; i++)
        newArr[i] = this->tranzactii[i];
    delete[] this->tranzactii;
    this->tranzactii = newArr;
}

void RepoTranzactii::add(const Tranzactie& t) {
    if (this->size == this->capacity)
        resize();
    this->tranzactii[this->size++] = t;
}

int RepoTranzactii::getSize() {
    return this->size;
}

Tranzactie RepoTranzactii::getTranzactie(int index) {
    return this->tranzactii[index];
}

RepoTranzactii::~RepoTranzactii() {
    delete[] this->tranzactii;
}