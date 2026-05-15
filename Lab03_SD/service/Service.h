#ifndef LAB03_SD_SERVICE_H
#define LAB03_SD_SERVICE_H

#pragma once
#include "../repository/RepoTranzactii.h"
#include "ATM.h"
#include "../TAD/MultimeOrdonata.h"

bool compId(Tranzactie a, Tranzactie b);
bool compSuma(Tranzactie a, Tranzactie b);
bool compData(Tranzactie a, Tranzactie b);
bool compNrBancnote(Tranzactie a, Tranzactie b);

class Service {
private:
    RepoTranzactii repo;
    ATM atm;
    int nextId;
public:
    Service();
    void adaugaBancnote(int valoare, int numar, Data data);
    Tranzactie retragere(int suma, Data data);
    // void afiseazaTranzactii();
    MultimeOrdonata<Tranzactie> getTransactionsSortedBySum();
    MultimeOrdonata<Tranzactie> getTransactionsSortedById();
    MultimeOrdonata<Tranzactie> getTransactionsSortedByData();
    MultimeOrdonata<Tranzactie> getTransactionsSortedByNoBanknotes();
};


#endif //LAB03_SD_SERVICE_H