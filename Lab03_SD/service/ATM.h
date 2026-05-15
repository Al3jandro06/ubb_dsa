#ifndef LAB03_SD_ATM_H
#define LAB03_SD_ATM_H

#pragma once
#include "../TAD/Collection.h"

class ATM {
private:
    Collection<int> bancnote;
public:
    ATM();
    void adaugaBancnote(int valoare, int numar);
    int nrBancnoteDisponibile(int valoare);
    bool scoateBancnote(int valoare, int numar);

    Collection<int> getBancnote();
};


#endif //LAB03_SD_ATM_H