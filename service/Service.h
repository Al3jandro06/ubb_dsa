#ifndef LAB02_SD_SERVICE_H
#define LAB02_SD_SERVICE_H

#include "../repository/RepoTranzactii.h"
#include "ATM.h"

class Service {
private:
    RepoTranzactii repo;
    ATM atm;
    int nextId;
public:
    Service();
    void adaugaBancnote(int valoare, int numar);
    Tranzactie retragere(int suma); //TODO
    void afiseazaTranzactii();
};


#endif //LAB02_SD_SERVICE_H