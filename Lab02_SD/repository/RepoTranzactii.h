#ifndef LAB02_SD_REPOTRANZACTII_H
#define LAB02_SD_REPOTRANZACTII_H

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


#endif //LAB02_SD_REPOTRANZACTII_H