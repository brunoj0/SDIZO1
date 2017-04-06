//
// Created by brunoj on 18.02.17.
//

#ifndef SDIZO_1_LISTA_H
#define SDIZO_1_LISTA_H

#include <clocale>
#include <iostream>

using namespace std;


class lista {
    struct Wezel

    {
        double wartosc;
        Wezel* next;
        Wezel* prev;


        Wezel(double d,Wezel *n=0,Wezel *p=0)
        {
            wartosc = d;
            next = n;
            prev=p;
        }

    };
public:

    lista(){
        poczatek=koniec=0;
    }
    void losowa(int);
    void zpliku(string path);
    void dodajpocz(int);
    void dodajWMiejscu(int element, int szukany);//za szukanym dodajemy
    void dodajkoniec(int);
    void usun(int);
    void usunpocz();
    void usunkoniec();
    void usunZMiejsca(int element);
    void usunKonkretna(int element);
    void znajdz(int);
    void wyswietl();

    void dodajWielokrotniePoczatek(int,int);
    void dodajWielokrotnieKoniec(int, int);
    void dodajWielokrotnieDowolne(int, int);
    void usunWielokrotniePoczatek(int, int);
    void usunWielokrotnieKoniec(int, int);
    void usunWielokrotnieDowolny(int, int);

private:


    Wezel *poczatek, *koniec;
};


#endif //SDIZO_1_LISTA_H
