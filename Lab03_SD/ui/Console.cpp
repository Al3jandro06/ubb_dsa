#include <iostream>
#include "Console.h"
using namespace std;

Console::Console() {

}

void Console::meniu() {
    cout << "\n-----------ATM--------\n";
    cout << "1. Adauga bancnote\n";
    cout << "2. Retragere suma\n";
    cout << "3. Afiseaza tranzactii sortate dupa id\n";
    cout << "4. Afiseaza tranzactii sortate dupa suma\n";
    cout << "5. Afiseaza tranzactii sortate dupa data\n";
    cout << "6. Afiseaza tranzactii sortate dupa numarul de bancnote\n";
    cout << "0. Exit\n";
}

void Console::run() {
    int optiune;

    do {
        meniu();
        cout<<"Introduceti optiunea: ";
        cin>>optiune;
        cout<<endl;
        switch (optiune) {
            case 0:
                cout<<"La revedere!"<<endl;
                break;
            case 1:
                adaugaBancnote();
                break;
            case 2:
                retragereNumerar();
                break;
            case 3:
                afisareTranzactiiSortateDupaId();
                break;
            case 4:
                afisareTranzactiiSortateDupaSuma();
                break;
            case 5:
                afisareTranzactiiSortateDupaData();
                break;
            case 6:
                afisareTranzactiiSortateDupaNrBancnote();
                break;
            default:
                cout<<"Aceasta optiune nu exista! :("<<'\n';
        }
    }while (optiune!=0);
}

void Console::adaugaBancnote() {
    int valoare, numar, zi, luna, an;
    cout<<"Introduceti valoarea bancnotei: ";
    cin>>valoare;
    cout<<"Introduceti numarul de bancnote: ";
    cin>>numar;
    cout<<"Introduceti data: "<<'\n';
    cout<<"Zi: ";
    cin>>zi;
    cout<<"Luna: ";
    cin>>luna;
    cout<<"An: ";
    cin>>an;
    Data data;
    data.zi = zi;
    data.luna = luna;
    data.an = an;
    this->srv.adaugaBancnote(valoare, numar, data);
}

void Console::retragereNumerar() {
    int suma, zi, luna, an;
    cout<<"Introduceti suma: ";
    cin>>suma;
    cout<<"Introduceti data: "<<'\n';
    cout<<"Zi: ";
    cin>>zi;
    cout<<"Luna: ";
    cin>>luna;
    cout<<"An: ";
    cin>>an;
    Data data;
    data.zi = zi;
    data.luna = luna;
    data.an = an;
    Tranzactie t = this->srv.retragere(suma, data);
    if (t.getId() == -1)
        cout<<"Nu se poate retrage suma!"<<'\n';
    else {
        BancnotaPlata* b = t.getBancnote();
        cout<<"Bancnote: ";
        for (int i = 0; i < t.getNrBancnote(); i++ ) {
            cout<<b[i].numar<<"x"<<b[i].valoare<<" ";
        }
    }
}

void Console::afisareTranzactiiSortateDupaId() {
    MultimeOrdonata<Tranzactie> m = this->srv.getTransactionsSortedById();
    for (int i = 0; i < m.size(); i++) {
        Tranzactie t = m.getAt(i);
        cout << "Tranzactie: id: " << t.getId() << ", suma: " << t.getSuma() << ", bancnote: ";
        for (int j = 0; j < t.getNrBancnote(); j++) {
            BancnotaPlata b = t.getBancnote()[j];
            cout << b.numar << "x" << b.valoare << " ";
        }
        cout<<", Data: "<<t.getData().zi<<"."<<t.getData().luna<<"."<<t.getData().an;
        cout << endl;
    }
}

void Console::afisareTranzactiiSortateDupaSuma() {
    MultimeOrdonata<Tranzactie> m = this->srv.getTransactionsSortedBySum();
    for (int i = 0; i < m.size(); i++) {
        Tranzactie t = m.getAt(i);
        cout << "Tranzactie: id: " << t.getId() << ", suma: " << t.getSuma() << ", bancnote: ";
        for (int j = 0; j < t.getNrBancnote(); j++) {
            BancnotaPlata b = t.getBancnote()[j];
            cout << b.numar << "x" << b.valoare << " ";
        }
        cout<<", Data: "<<t.getData().zi<<"."<<t.getData().luna<<"."<<t.getData().an;
        cout << endl;
    }
}

void Console::afisareTranzactiiSortateDupaData() {
    MultimeOrdonata<Tranzactie> m = this->srv.getTransactionsSortedByData();
    for (int i = 0; i < m.size(); i++) {
        Tranzactie t = m.getAt(i);
        cout << "Tranzactie: id: " << t.getId() << ", suma: " << t.getSuma() << ", bancnote: ";
        for (int j = 0; j < t.getNrBancnote(); j++) {
            BancnotaPlata b = t.getBancnote()[j];
            cout << b.numar << "x" << b.valoare << " ";
        }
        cout<<", Data: "<<t.getData().zi<<"."<<t.getData().luna<<"."<<t.getData().an;
        cout << endl;
    }
}

void Console::afisareTranzactiiSortateDupaNrBancnote() {
    MultimeOrdonata<Tranzactie> m = this->srv.getTransactionsSortedByNoBanknotes();
    for (int i = 0; i < m.size(); i++) {
        Tranzactie t = m.getAt(i);
        cout << "Tranzactie: id: " << t.getId() << ", suma: " << t.getSuma() << ", bancnote: ";
        for (int j = 0; j < t.getNrBancnote(); j++) {
            BancnotaPlata b = t.getBancnote()[j];
            cout << b.numar << "x" << b.valoare << " ";
        }
        cout<<", Data: "<<t.getData().zi<<"."<<t.getData().luna<<"."<<t.getData().an;
        cout << endl;
    }
}
