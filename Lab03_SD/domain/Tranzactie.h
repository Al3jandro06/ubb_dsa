#ifndef LAB03_SD_TRANZACTIE_H
#define LAB03_SD_TRANZACTIE_H

#pragma once

struct BancnotaPlata {
    int valoare;
    int numar;
};

struct Data {
    int zi;
    int luna;
    int an;
};

class Tranzactie {
private:
    int id;
    int suma;
    BancnotaPlata* bancnote;
    int nrBancnote;
    Data data;
public:
    Tranzactie();
    Tranzactie(int id, int suma, BancnotaPlata* b, int nr, Data d);
    Tranzactie(const Tranzactie& other);
    Tranzactie& operator=(const Tranzactie& other);

    bool operator==(const Tranzactie& other) const;

    int getId();
    int getSuma();
    BancnotaPlata* getBancnote();
    int getNrBancnote();
    Data getData();

    ~Tranzactie();
};


#endif //LAB03_SD_TRANZACTIE_H