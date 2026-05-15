#ifndef LAB03_SD_REPOTRANZACTII_H
#define LAB03_SD_REPOTRANZACTII_H

#pragma once
#include "../domain/Tranzactie.h"

class RepoTranzactii {
private:
    Tranzactie* tranzactii;
    int size;
    int capacity;
    void resize();
public:
    RepoTranzactii();
    void add(const Tranzactie& t);
    int getSize();
    Tranzactie getTranzactie(int index);
    ~RepoTranzactii();
};


#endif //LAB03_SD_REPOTRANZACTII_H