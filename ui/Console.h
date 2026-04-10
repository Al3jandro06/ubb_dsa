#ifndef LAB02_SD_CONSOLE_H
#define LAB02_SD_CONSOLE_H

#include "../service/Service.h"

class Console {
private:
    Service srv;
    void meniu();
public:
    Console();
    void run();//TODO
    void adaugaBancnote();
    void retragereNumerar();
    void afisareTranzactii();
};


#endif //LAB02_SD_CONSOLE_H