#include "Tranzactie.h"

Tranzactie::Tranzactie() {
    this->id = -1;
    this->suma = 0;
    this->bancnote = nullptr;
    this->nrBancnote = 0;
}

Tranzactie::Tranzactie(int id, int suma, BancnotaPlata* b, int nr) {
    this->id = id;
    this->suma = suma;
    this->nrBancnote = nr;
    this->bancnote = new BancnotaPlata[nr];
    for (int i = 0; i < nr; i++) {
        this->bancnote[i] = b[i];
    }
}

Tranzactie::Tranzactie(const Tranzactie &other) {
    this->id = other.id;
    this->suma = other.suma;
    this->nrBancnote = other.nrBancnote;
    this->bancnote = new BancnotaPlata[this->nrBancnote];
    for (int i = 0; i < this->nrBancnote; i++) {
        this->bancnote[i] = other.bancnote[i];
    }
}

Tranzactie& Tranzactie::operator=(const Tranzactie &other) {
    if (this != &other) {
        if (this->bancnote != nullptr)
            delete[] this->bancnote;
        this->id = other.id;
        this->suma = other.suma;
        this->nrBancnote = other.nrBancnote;
        this->bancnote = new BancnotaPlata[this->nrBancnote];
        for (int i = 0; i < this->nrBancnote; i++) {
            this->bancnote[i] = other.bancnote[i];
        }
    }
    return *this;
}

bool Tranzactie::operator==(const Tranzactie &other) {
    if (this->id != other.id || this->suma != other.suma || this->nrBancnote != other.nrBancnote)
        return false;

}

int Tranzactie::getId() {
    return this->id;
}

int Tranzactie::getSuma() {
    return this->suma;
}

BancnotaPlata* Tranzactie::getBancnote() {
    return this->bancnote;
}

int Tranzactie::getNrBancnote() {
    return this->nrBancnote;
}

Tranzactie::~Tranzactie() {
    delete[] this->bancnote;
}