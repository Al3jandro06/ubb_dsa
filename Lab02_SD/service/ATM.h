#ifndef LAB02_SD_ATM_H
#define LAB02_SD_ATM_H

#include "../TAD/Collection.h"

class ATM {
private:
    Collection bancnote;
public:
    ATM();
    void adaugaBancnote(int valoare, int numar);
    int nrBancnoteDisponibile(int valoare);
    bool scoateBancnote(int valoare, int numar);

    Collection getBancnote();
};


#endif //LAB02_SD_ATM_H