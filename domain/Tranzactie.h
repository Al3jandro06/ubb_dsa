#ifndef LAB02_SD_TRANZACTIE_H
#define LAB02_SD_TRANZACTIE_H

struct BancnotaPlata {
    int valoare;
    int numar;
};

class Tranzactie {
private:
    int id;
    int suma;
    BancnotaPlata* bancnote;
    int nrBancnote;
public:
    Tranzactie();
    Tranzactie(int id, int suma, BancnotaPlata* b, int nr);
    Tranzactie(const Tranzactie& other);
    Tranzactie& operator=(const Tranzactie& other);

    //Todo: operator==
    bool operator==(const Tranzactie& other);

    int getId();
    int getSuma();
    BancnotaPlata* getBancnote();
    int getNrBancnote();

    ~Tranzactie();
};


#endif //LAB02_SD_TRANZACTIE_H