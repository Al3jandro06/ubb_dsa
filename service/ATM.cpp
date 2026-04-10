#include "ATM.h"

ATM::ATM() {
    // implicit Collection este vida
}

void ATM::adaugaBancnote(int valoare, int numar) {
    for (int i = 0; i < numar; i++)
        this->bancnote.add(valoare);
}

int ATM::nrBancnoteDisponibile(int valoare) {
    return this->bancnote.noOccurrences(valoare);
}

bool ATM::scoateBancnote(int valoare, int numar) {
    for (int i = 0; i < numar; i++)
        if (!this->bancnote.remove(valoare))
            return false;
    return true;
}


Collection ATM::getBancnote() {
    return this->bancnote;
}
