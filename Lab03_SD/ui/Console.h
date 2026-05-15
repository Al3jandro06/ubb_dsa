#ifndef LAB03_SD_CONSOLE_H
#define LAB03_SD_CONSOLE_H

#pragma once
#include "../service/Service.h"

class Console {
private:
    Service srv;
    void meniu();
public:
    Console();
    void run();
    void adaugaBancnote();
    void retragereNumerar();
    void afisareTranzactiiSortateDupaId();
    void afisareTranzactiiSortateDupaSuma();
    void afisareTranzactiiSortateDupaData();
    void afisareTranzactiiSortateDupaNrBancnote();
};


#endif //LAB03_SD_CONSOLE_H