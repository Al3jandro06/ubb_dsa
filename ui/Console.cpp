#include <iostream>
#include "Console.h"
using namespace std;

Console::Console() {

}

void Console::meniu() {
    cout << "\n-----------ATM--------\n";
    cout << "1. Adauga bancnote\n";
    cout << "2. Retragere suma\n";
    cout << "3. Afiseaza tranzactii\n";
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
                afisareTranzactii();
                break;
            default:
                cout<<"Aceasta optiune nu exista! :("<<'\n';
        }
    }while (optiune!=0);
}

void Console::adaugaBancnote() {
    int valoare, numar;
    cout<<"Introduceti valoarea bancnotei: ";
    cin>>valoare;
    cout<<"Introduceti numarul de bancnote: ";
    cin>>numar;
    this->srv.adaugaBancnote(valoare, numar);
}

void Console::retragereNumerar() {
    int suma;
    cout<<"Introduceti suma: ";
    cin>>suma;
    Tranzactie t = this->srv.retragere(suma);
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

void Console::afisareTranzactii() {
    this->srv.afiseazaTranzactii();
}