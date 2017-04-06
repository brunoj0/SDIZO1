//
// Created by brunoj on 01.03.17.
//


#include "tablica.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <fcntl.h>
#include <chrono>

typedef std::chrono::high_resolution_clock Clock;
using namespace std;
tablica::tablica() {
    size=0;
    wskaznik=new int[size];

}
void tablica::dodajWMiejscu(int element, int pozycja) {
    bufor=new int[size+1];

    for(int i=0; i<pozycja;i++){
        bufor[i]=wskaznik[i];
    }
    bufor[pozycja]=element;
    for(int i=pozycja;i<size;i++){
        bufor[i+1]=wskaznik[i];
    }
    size=size+1;

    wskaznik=new int[size];
    wskaznik=bufor;


}
void tablica::dodajPrzod(int a) {
    bufor=new int[size+1];
    bufor[0]=a;
    for(int i=0; i<size;i++){
        bufor[i+1]=wskaznik[i];
    }

    size=size+1;

    wskaznik=new int[size];

    wskaznik=bufor;


}


void tablica::wyszukaj(int szukany) {
    bool znaleziony=false;
    for(int i=0;i<size;i++){
        if(wskaznik[i]==szukany){
            znaleziony=true;
        }
    }
    if(znaleziony) {
        cout << "element " << szukany << " znajduje sie w tablicy" << endl;
    }
    else{
        cout << "element " << szukany << " NIE znajduje sie w tablicy" << endl;
    }

}
void tablica::dodajTyl(int a){
    bufor=new int[size+1];
    for(int i=0; i<size;i++){
        bufor[i]=wskaznik[i];
    }
    bufor[size]=a;
    size=size+1;
    wskaznik=new int[size];
    wskaznik=bufor;

}

void tablica::usunTyl() {
    bufor=new int[size-1];
    for(int i=0;i<size-1;i++)
    {
        bufor[i]=wskaznik[i];
    }
    size-=1;
    wskaznik=new int[size];
    wskaznik=bufor;
}

void tablica::usupPzod() {
    bufor=new int[size-1];
    for(int i=1;i<size;i++)
    {
        bufor[i-1]=wskaznik[i];
    }
    size-=1;
    wskaznik=new int[size];
    wskaznik=bufor;
}

void tablica::nowaTablica(int s) {
    srand( time( NULL ) );
    size=s;
    wskaznik=new int[size];
    for( int i=0; i<size; i++){
        wskaznik[i]=rand();
    }
}
void tablica::usunZMiejsca(int indeks) {
    bufor =new int[size-1];
    for(int i=0;i<indeks;i++){
        bufor[i]=wskaznik[i];
    }
    for(int i=indeks;i<size-1;i++){
        bufor[i]=wskaznik[i+1];
    }
    wskaznik=new int[size-1];
    wskaznik=bufor;
}

void tablica::zpliku(string path) {


    string bufor;
    int var;
    int help;

    fstream plik( path.c_str(), ios::in);
    getline(plik,bufor);
    help = stoi(bufor);
    size=help;
    wskaznik=new int[size];
    for(int i=0;i<help;i++){
        getline(plik,bufor);
        var=stoi(bufor);
        wskaznik[i]=var;
    }
    plik.close();
}

void tablica::wyswietlTablice() {
    cout<<"wnetrze tablicy ktora ma "<<size<<" elemenow"<<endl;
    for(int i=0; i<size;i++){
        cout<<"1:"<<wskaznik[i]<<endl;
    }
}

void tablica::dodajWielokrotniePoczatektab(int wielkosc, int ilerazy) {
    nowaTablica(wielkosc);
    int element;
    double time=0;
    for(int i=0;i<ilerazy;i++){
        element = rand()%1000;
        auto t1=Clock::now();
        dodajPrzod(element);
        auto t2=Clock::now();
        time+=std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();

    }
    time=time/ilerazy;
    cout <<"sredni czas to:"<< time << " ms.\n";
}



void tablica::dodajWielokrotnieKoniectab(int wielkosc, int ilerazy) {
    nowaTablica(wielkosc);
    int element;
    double time=0;
    for(int i=0;i<ilerazy;i++){
        element = rand()%1000;
        auto t1=Clock::now();
        dodajTyl(element);
        auto t2=Clock::now();
        time+=std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();

    }
    time=time/ilerazy;
    cout <<"sredni czas to:"<< time << " ms.\n";
}

void tablica::dodajWielokrotnieDowolnetab(int wielkosc, int ilerazy) {
    nowaTablica(wielkosc);
    int losowa=rand()%size;
    int element;
    double time=0;
    for(int i=0;i<ilerazy;i++){
        element = rand()%1000;
        losowa=rand()%size;
        auto t1=Clock::now();
        dodajWMiejscu(element,losowa);
        auto t2=Clock::now();
        time+=std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();

    }
    time=time/ilerazy;
    cout <<"sredni czas to:"<< time << " ms.\n";
}

void tablica::usunWielokrotnieKoniectab(int wielkosc, int ilerazy) {
    nowaTablica(wielkosc);
    double time=0;
    for(int i=0;i<ilerazy;i++){
        auto t1=Clock::now();
        usupPzod();
        auto t2=Clock::now();
        time+=std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();

    }
    time=time/ilerazy;
    cout <<"sredni czas to:"<< time << " ms.\n";
}

void tablica::usunWielokrotniePoczatektab(int wielkosc, int ilerazy) {
    nowaTablica(wielkosc);
    double time=0;
    for(int i=0;i<ilerazy;i++){
        auto t1=Clock::now();
        usupPzod();
        auto t2=Clock::now();
        time+=std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();

    }
    time=time/ilerazy;
    cout <<"sredni czas to:"<< time << " ms.\n";
}
