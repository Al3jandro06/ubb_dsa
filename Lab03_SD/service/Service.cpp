#include <iostream>
#include "Service.h"
using namespace std;

bool compId(Tranzactie a, Tranzactie b) {
    return a.getId() < b.getId();
}

bool compSuma(Tranzactie a, Tranzactie b) {
    return a.getSuma() < b.getSuma();
}

bool compData(Tranzactie a, Tranzactie b) {
    return (a.getData().an < b.getData().an ||
        (a.getData().an == b.getData().an && a.getData().luna < b.getData().luna) ||
        (a.getData().an == b.getData().an && a.getData().luna == b.getData().luna && a.getData().zi < b.getData().zi));
}

bool compNrBancnote(Tranzactie a, Tranzactie b) {
    return a.getNrBancnote() < b.getNrBancnote();
}

Service::Service() {
    this->nextId = 1;
}

void Service::adaugaBancnote(int valoare, int numar, Data data) {
    this->atm.adaugaBancnote(valoare, numar);
    int suma = numar * valoare;
    BancnotaPlata bancnota;
    bancnota.valoare = valoare;
    bancnota.numar = numar;
    BancnotaPlata* b = new BancnotaPlata(bancnota);
    Tranzactie t(this->nextId, suma, b, 1, data);
    this->repo.add(t);
    delete b;
    this->nextId++;
}

Tranzactie Service::retragere(int suma, Data data) {
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
        int numar = this->atm.getBancnote().nrOccurrences(valoare);
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
        Tranzactie t(-1, 0, nullptr, 0, data);
        return t;
    }

    BancnotaPlata* b = new BancnotaPlata[dp[suma]];
    int curent = suma, i = 0;
    while (curent > 0) {
        b[i].valoare = usedBancnota[curent];
        b[i].numar = usedCount[curent];
        // Remove the banknotes from the ATM
        if (this->atm.scoateBancnote(b[i].valoare, b[i].numar)) {
            // Successfully removed the banknotes
        } else {
            Tranzactie t(-1, 0, nullptr, 0, data);
            return t;
        }
        curent = parent[curent];
        i++;
    }
    Tranzactie t(this->nextId, suma, b, i, data);
    this->repo.add(t);
    delete[] b;
    this->nextId++;
    return t;
}

// void Service::afiseazaTranzactii() {
//     for (int i = 0; i < this->repo.getSize(); i++) {
//         Tranzactie t = this->repo.getTranzactie(i);
//         cout << "Tranzactie: id=" << t.getId() << ", suma=" << t.getSuma() << ", bancnote: ";
//         for (int j = 0; j < t.getNrBancnote(); j++) {
//             BancnotaPlata b = t.getBancnote()[j];
//             cout << b.numar << "x" << b.valoare << " ";
//         }
//         cout << endl;
//     }
// }

MultimeOrdonata<Tranzactie> Service::getTransactionsSortedBySum() {
    MultimeOrdonata<Tranzactie> m(compSuma);
    for (int i = 0; i < this->repo.getSize(); i++) {
        Tranzactie t = this->repo.getTranzactie(i);
        m.add(t);
    }
    return m;
}


MultimeOrdonata<Tranzactie> Service::getTransactionsSortedById() {
    MultimeOrdonata<Tranzactie> m(compId);
    for (int i = 0; i < this->repo.getSize(); i++) {
        Tranzactie t = this->repo.getTranzactie(i);
        m.add(t);
    }
    return m;
}

MultimeOrdonata<Tranzactie> Service::getTransactionsSortedByData() {
    MultimeOrdonata<Tranzactie> m(compData);
    for (int i = 0; i < this->repo.getSize(); i++) {
        Tranzactie t = this->repo.getTranzactie(i);
        m.add(t);
    }
    return m;
}

MultimeOrdonata<Tranzactie> Service::getTransactionsSortedByNoBanknotes() {
    MultimeOrdonata<Tranzactie> m(compNrBancnote);
    for (int i = 0; i < this->repo.getSize(); i++) {
        Tranzactie t = this->repo.getTranzactie(i);
        m.add(t);
    }
    return m;
}
