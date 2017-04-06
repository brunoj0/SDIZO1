//
// Created by brunoj on 24.02.17.
//

#include "menu.h"
#include "lista.h"
#include "tablica.h"
#include "binaryheap.h"
#include <iostream>
using namespace std;
menu::menu() {

    int petla=1;
    do {
        int x;
        cout << "POJEKT SDIZO NR1" << endl;
        cout << "1 - Tablica" << endl;
        cout << "2 - Lista" << endl;
        cout << "3 - Kopiec Binarny" << endl;
        cout << "4 - Drzewo Czerwono-Czarne" << endl;

        cin >> x;
        switch (x) {
            case 1:
                Tablica();
                petla=0;
                break;
            case 2:
                Lista();
                petla=0;
                break;
            case 3:
                BinaryHeap();
                petla=0;
            default: {
                cout << "Error";
                break;

            }
        }
    }while(petla==1);
}
void menu::Lista() {
    string path;
    lista Lista;
    int koniec=0;
    do {
        int x;
        int element;
        cout << "1 - Stworz losowo generowana liste" << endl;
        cout << "2 - Wczytaj liste z pliku" << endl;
        cout << "3 - Dodaj   liczbe do listy na poczatku" << endl;
        cout << "4 - Dodaj  liczbe do listy na koncu " << endl;
        cout << "5 - usun ostatni element"<<endl;
        cout << "6 - usun pierwszy element"<<endl;
        cout << "7 - Wyszukaj element w liscie" << endl;
        cout << "8 - Wyswietl Liste"<<endl;
        cout << "9 - dodaj za liczba" << endl;
        cout << "10 - Test" << endl;

        cout << "11 - zakoncz program" << endl;
        cin>>x;
        cout<<endl;
        switch (x) {
            case 1:
                int ilosc;
                cout << "Ilu elementowa ma być lista?" << endl;
                cin >> ilosc;
                Lista.losowa(ilosc);
                cout << endl;
                break;
            case 2:
                cout<<"Podaj sciezke do pliku"<<endl;
                cin >>path;
                Lista.zpliku(path);
                break;
            case 3:

                cout<<"jaka liczba ma zostac dodana?"<<endl;
                cin>>element;
                Lista.dodajpocz(element);
                break;
            case 4:
                cout<<"jaka liczba ma zostac dodana?"<<endl;
                cin>>element;
                Lista.dodajkoniec(element);
                break;
                break;
            case 5:
                cout<<"usun ostatni element"<<endl;
                Lista.usunkoniec();
                cout<<"Ostatni element zostal usuniety pomyslnie"<<endl;
                break;
            case 6:
                cout<<"usun pierwszy elemnet"<<endl;
                Lista.usunpocz();
                cout<<"Poczatkow element zostal usuniety pomyslnie"<<endl;
                break;
            case 7:
                cout<<"jakiej wartosci szukasz?"<<endl;
                cin>>element;
                Lista.znajdz(element);
                break;
            case 8:
                Lista.wyswietl();
                break;
            case 9:
                int szukany;
                cout<<"za jaka wartoscia umiescic liczbe?"<<endl;
                cin>>szukany;
                cout<<endl<<"jaka liczba ma zostac dodana"<<endl;
                cin>>element;
                Lista.dodajWMiejscu(szukany,element);

                break;
            case 10:
                int test;
                cout<<" 1 - dodaj Wielokrotnie Poczatek"<<endl;
                cout<<" 2 - dodaj Wielokrotnie Koniec"<<endl;
                cout<<" 3 - dodaj Wielokrotnie Dowolny"<<endl;
                cout<<" 4 - usun Wielokrotnie Poczatek"<<endl;
                cout<<" 5 - usun Wielokrotnie Koniec"<<endl;
                cout<<" 6 - usun Wielokrotnie Dowolny"<<endl;
                cin>>test;
                switch(test) {
                    case 1:
                        cout << " ilu elementowa ma byc lista?" << endl;
                        cin >> ilosc;
                        cout << endl;
                        cout << "ile razy ma zostac powtorzona operacja" << endl;
                        cin >> element;
                        Lista.dodajWielokrotniePoczatek(ilosc, element);
                        break;
                }
            case 11:
                koniec=1;
                break;
        }
    }while(koniec==0);
}
void menu::Tablica() {
    tablica Tablica;
    int koniec=0;
    do {
        int x;
        string path;
        int element;
        cout << "1 - Stworz losowo generowana tablice" << endl;
        cout << "2 - Wczytaj tablice z pliku" << endl;
        cout << "3 - Dodaj   liczbe do tablicy na poczatku" << endl;
        cout << "4 - Dodaj  liczbe do tablicy na koncu " << endl;
        cout << "5 - Usun liczbe z konca tablicy" << endl;
        cout << "6 - Usun liczbe z poczatku tablicy" << endl;
        cout << "7 - Wyszukaj element w tablicy" << endl;
        cout << "8 - Wyswietl tablce"<<endl;
        cout <<" 9 - Dodaj liczbe w okreslonym miejscu "<<endl;
        cout << "10 - Usun Liczbe z okreslonego miejsca"<<endl;
        cout << "11 - Testy" << endl;
        cout << "12 - zakoncz program" << endl;
        cin>>x;
        cout<<endl;
        switch (x) {
            case 1:
                int ilosc;
                cout << "Ilu elementowa ma być tablica?" << endl;
                cin >> ilosc;
                Tablica.nowaTablica(ilosc);
                cout << endl;
                break;
            case 2:
                cout<<"Podaj sciezke do pliku"<<endl;
                cin >>path;
                Tablica.zpliku(path);
                break;
            case 3:

                cout<<"jaka liczba ma zostac dodana?"<<endl;
                cin>>element;
                Tablica.dodajPrzod(element);
                break;
            case 4:
                cout<<"jaka liczba ma zostac dodana?"<<endl;
                cin>>element;
                Tablica.dodajTyl(element);
                break;
                break;
            case 5:
                Tablica.usunTyl();
                cout<<"Ostatni element zostal usuniety pomyslnie"<<endl;
                break;
            case 6:
                Tablica.usupPzod();
                cout<<"Poczatkow element zostal usuniety pomyslnie"<<endl;
                break;
            case 7:
                cout<<"jakiej wartosci szukasz?"<<endl;
                cin>>element;
                Tablica.wyszukaj(element);
                break;
            case 8:
                Tablica.wyswietlTablice();
                break;
            case 9:
                int szukany;
                cout<<"W jakim miejscu  umiescic liczbe?"<<endl;
                cin>>szukany;
                cout<<endl<<"jaka liczba ma zostac dodana"<<endl;
                cin>>element;
                Tablica.dodajWMiejscu(element,szukany);
                break;
            case 10:
                cout<<"z jakiego miejsca chcesz usunac liczbe?"<<endl;
                cin>>szukany;
                Tablica.usunZMiejsca(szukany);
                break;
            case 11:
                int test;
                cout<<" 1 - dodaj Wielokrotnie Poczatek"<<endl;
                cout<<" 2 - dodaj Wielokrotnie Koniec"<<endl;
                cout<<" 3 - dodaj Wielokrotnie Dowolny"<<endl;
                cout<<" 4 - usun Wielokrotnie Poczatek"<<endl;
                cout<<" 5 - usun Wielokrotnie Koniec"<<endl;
                cout<<" 6 - usun Wielokrotnie Dowolny"<<endl;
                cin>>test;
                switch(test) {
                    case 1:
                        cout << " ilu elementowa ma byc Tablica?" << endl;
                        cin >> ilosc;
                        cout << endl;
                        cout << "ile razy ma zostac powtorzona operacja" << endl;
                        cin >> element;
                        Tablica.dodajWielokrotniePoczatektab(ilosc,element);
                        break;

                }
                break;
            case 12:
                koniec=1;
                break;
        }
    }while(koniec==0);
}
void menu::BinaryHeap() {
    binaryheap BinaryHeap;
    int koniec=0;
    do {
        int x;
        string path;
        int element;
        cout << "1 - Stworz losowo generowany kopiec binarny" << endl;
        cout << "2 - Wczytaj kopiec z pliku" << endl;
        cout << "3 - Dodaj   element do kopca" << endl;
        cout << "4 - Usun liczbe z kopca" << endl;
        cout << "5 - Wyszukaj element w kopcu" << endl;
        cout << "6 - Wyswietl kopiec"<<endl;
        cout << "7 - zakoncz program" << endl;
        cin>>x;
        cout<<endl;
        switch (x) {
            case 1:
                cout<<"ilu elementowy ma byc kopiec?"<<endl;
                cin>>element;
                BinaryHeap.createRandom(element);
                break;
            case 2:
                cout<<"podaj sciezke do pliku"<<endl;
                cin>>path;
                BinaryHeap.FromFile(path);
                break;
            case 3:

                cout<<"jaka liczba ma zostac dodana?"<<endl;
                cin>>element;
                BinaryHeap.addElement(element);
                break;
            case 4:
                cout<<"jaka liczba ma zostac usunieta?"<<endl;
                cin>>element;
                BinaryHeap.deleteElement(element);
                break;
                break;
            case 5:
                cout<<"jakiego elementu szukasz?"<<endl;
                cin>>element;
                BinaryHeap.search(element);
                break;
            case 6:
                BinaryHeap.print();
                break;
            case 7:
                koniec=1;

        }
    }while(koniec==0);
}
menu::~menu() {}