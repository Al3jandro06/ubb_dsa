#include <iostream>
#include "Service.h"
using namespace std;

Service::Service() {
    this->nextId = 1;
}

void Service::adaugaBancnote(int valoare, int numar) {
    this->atm.adaugaBancnote(valoare, numar);
    int suma = numar * valoare;
    BancnotaPlata bancnota;
    bancnota.valoare = valoare;
    bancnota.numar = numar;
    BancnotaPlata* b = new BancnotaPlata(bancnota);
    Tranzactie t(this->nextId, suma, b, 1);
    this->repo.add(t);
    delete b;
    this->nextId++;
}

Tranzactie Service::retragere(int suma) {
    const int SUP = 1000000000;
    int dp[suma + 1], parent[suma + 1], usedBancnota[suma + 1], usedCount[suma + 1];
    for (int i = 1; i <= suma; i++) {
        dp[i] = SUP;
        parent[i] = usedBancnota[i] = -1;
        usedCount[i] = 0;
    }
    dp[0] = 0;

    for (int i = 0; i < this->atm.getBancnote().size(); i++) {
        int valoare = this->atm.getBancnote().getAt(i);
        int numar = this->atm.getBancnote().noOccurrences(valoare);
        for (int j = suma; j >= 0; j--) {
            if (dp[j] == SUP) continue;
            for (int c = 1; c <= numar; c++) {
                int newSum = j + c * valoare;
                if (newSum > suma)
                    c = numar + 1;
                else {
                    if (dp[newSum] > dp[j] + c) {
                        dp[newSum] = dp[j] + c;
                        parent[newSum] = j;
                        usedBancnota[newSum] = valoare;
                        usedCount[newSum] = c;
                    }
                }
            }
        }
    }

    if (dp[suma] == SUP) {
        Tranzactie t(-1, 0, nullptr, 0);
        return t;
    }

    BancnotaPlata* b = new BancnotaPlata[dp[suma]];
    int curent = suma, i = 0;
    while (curent > 0) {
        b[i].valoare = usedBancnota[curent];
        b[i].numar = usedCount[curent];
        // Remove the banknotes from the ATM
        this->atm.scoateBancnote(b[i].valoare, b[i].numar);
        curent = parent[curent];
        i++;
    }
    Tranzactie t(this->nextId, suma, b, i);
    this->repo.add(t);
    delete[] b;
    this->nextId++;
    return t;
}

void Service::afiseazaTranzactii() {
    for (int i = 0; i < this->repo.getSize(); i++) {
        Tranzactie t = this->repo.getTranzactie(i);
        cout << "Tranzactie: id=" << t.getId() << ", suma=" << t.getSuma() << ", bancnote: ";
        for (int j = 0; j < t.getNrBancnote(); j++) {
            BancnotaPlata b = t.getBancnote()[j];
            cout << b.numar << "x" << b.valoare << " ";
        }
        cout << endl;
    }
}
