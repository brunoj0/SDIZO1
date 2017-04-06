//
// Created by brunoj on 01.03.17.
//

#ifndef SDIZO_1_TABLICA_H
#define SDIZO_1_TABLICA_H

#include<iostream>

class tablica {
public:

    tablica();
    void dodajPrzod(int);
    void dodajTyl(int);
    void wyszukaj(int);
    void usunTyl();
    void usunZMiejsca(int);
    void usupPzod();
    void dodajWMiejscu(int element, int pozycja);
    void wyswietlTablice();
    void nowaTablica(int);
    void zpliku(std::string path);

    void dodajWielokrotniePoczatektab(int,int);
    void dodajWielokrotnieKoniectab(int, int);
    void dodajWielokrotnieDowolnetab(int, int);
    void usunWielokrotniePoczatektab(int, int);
    void usunWielokrotnieKoniectab(int, int);
    void usunWielokrotnieDowolnytab(int, int);
private:
    int size;
    int *wskaznik;
    int *bufor;

};


#endif //SDIZO_1_TABLICA_H
