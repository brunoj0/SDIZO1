//
// Created by brunoj on 18.02.17.
//

#include "lista.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <chrono>
typedef std::chrono::high_resolution_clock Clock;
using namespace std;

void lista::dodajpocz(int element) {

    if(poczatek != 0){
        poczatek->prev = new Wezel(element, poczatek, NULL);
        poczatek = poczatek->prev;
    }else{
       poczatek = koniec = new Wezel(element, NULL, NULL);
   }


}
void lista::usunKonkretna(int szukany){
    bool a=false;
    if(poczatek==koniec){
        if(poczatek->wartosc==szukany){
            usunpocz();
        }else{
            cout<<"nie ma takiej wartosci w liscie "<<endl;
        }
    }else{
        for(Wezel *tmp=poczatek;tmp!=0;tmp=tmp->next){
            if(tmp->wartosc==szukany){
                tmp->prev->next=tmp->next;
                tmp->next->prev=tmp->prev;
                delete tmp;
                tmp=0;
            }
        }
        if(a==false){
            cout<<"nie ma takiej wartosci w liscie "<<endl;
        }

    }
}

void lista::dodajWMiejscu(int element, int szukany) {
    bool a=false;
    if(poczatek==koniec){
        if(poczatek->wartosc==szukany){
            dodajkoniec(element);
        }else{
            dodajpocz(element);
        }
    }else{
        for(Wezel *tmp=poczatek;tmp!=0;tmp=tmp->next){
            if(tmp->wartosc==szukany){
                tmp=tmp->next;
                new Wezel(element,tmp->prev,tmp->next);
                *tmp=0;
                a=true;
            }
        }
        if(a==false){
           dodajpocz(element);
        }

    }
}
void lista::dodajkoniec(int element) {
    if(koniec!=0){

        koniec=new Wezel(element,NULL,koniec);
        koniec->prev->next=koniec;
    }else{
        koniec=poczatek=new Wezel(element);
    }

}

void lista::znajdz(int szukany) {
    bool a=false;
    if(poczatek==koniec){
        if(poczatek->wartosc==szukany){
            cout<<"wartosc "<<szukany<<"znajduje sie w liscie"<<endl;
        }else{
            cout<<"nie ma takiej wartosci w liscie "<<endl;
        }
    }else{
        for(Wezel *tmp=poczatek;tmp!=0;tmp=tmp->next){
          if(tmp->wartosc==szukany){
              cout<<"wartosc "<<szukany<<"znajuduje sie w liscie "<<endl;
              *tmp=0;
              a=true;
          }
        }
        if(a==false){
            cout<<"nie ma takiej wartosci w liscie "<<endl;
        }

    }
}





void lista::usunpocz() {

  if(poczatek==koniec){

      delete poczatek;
      koniec=poczatek=0;

  }else{
      poczatek=poczatek->next;
      delete poczatek->prev;
  }

}

void lista::usunkoniec() {
    int liczba=koniec->wartosc;

    if(poczatek==koniec){
        delete koniec;
        koniec=poczatek=0;
    }else{
        koniec=koniec->prev;
        delete koniec->next;
        koniec->next=0;
    }

}

void lista::losowa(int x) {
    while(poczatek){
        usunpocz();
    }
    srand( time( NULL ) );
    for(int i=0;i<x;i++){
        int liczba = rand()%1000;
        dodajpocz(liczba);
    }
}

void lista::zpliku(string path) {
    while (poczatek) {
        usunpocz();
    }
    fstream plik;
    string bufor;
    int var;
    plik.open( path.c_str(), ios::in);
    getline(plik,bufor);
    int size;
    try
    {
         size = stoi(bufor);

    }
    catch (const std::invalid_argument& e)
    {
        cout << "Invalid answeree : " << size << endl;
    }
    catch (const std::out_of_range& e)
    {
        cout << "Invalid answera : " << size << endl;
    };
    for(int i=0;i<size;i++){
        getline(plik,bufor);
        var=stoi(bufor);
        dodajkoniec(var);
    }
    plik.close();
}

void lista::wyswietl() {
    for(Wezel *tmp=poczatek;tmp!=0;tmp=tmp->next){
        cout<<tmp->wartosc<<"  "<<endl;

    }
}

void lista::dodajWielokrotniePoczatek(int wielkosc, int ilerazy) {
    losowa(wielkosc);
    int element;
    double time=0;
    for(int i=0;i<ilerazy;i++){
        element = rand()%1000;
        auto t1=Clock::now();
        dodajpocz(element);
        auto t2=Clock::now();
        time+=std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();

    }
    time=time/ilerazy;
    cout <<"sredni czas to:"<< time << " ms.\n";

}

void lista::dodajWielokrotnieKoniec(int wielkosc, int ilerazy) {
    losowa(wielkosc);
    int element;
    double time=0;
    for(int i=0;i<ilerazy;i++){
        element = rand()%1000;
        auto t1=Clock::now();
        dodajkoniec(element);
        auto t2=Clock::now();
        time+=std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();

    }
    time=time/ilerazy;
    cout <<"sredni czas to:"<< time << " ms.\n";
}

void lista::dodajWielokrotnieDowolne(int wielkosc, int ilerazy) {
    losowa(wielkosc);
    int element;
    int miejsce;
    double time=0;
    for(int i=0;i<ilerazy;i++){
        element = rand()%1000;
        miejsce = rand()%wielkosc;
        auto t1=Clock::now();
        dodajWMiejscu(element,miejsce);
        auto t2=Clock::now();
        time+=std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();

    }
    time=time/ilerazy;
    cout <<"sredni czas to:"<< time << " ms.\n";
}

void lista::usunWielokrotnieKoniec(int wielkosc, int ilerazy) {
    losowa(wielkosc);
    double time=0;
    for(int i=0;i<ilerazy;i++){
        auto t1=Clock::now();
        usunkoniec();
        auto t2=Clock::now();
        time+=std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();

    }
    time=time/ilerazy;
    cout <<"sredni czas to:"<< time << " ms.\n";
}

void lista::usunWielokrotniePoczatek(int wielkosc, int ilerazy) {
    losowa(wielkosc);
    double time=0;
    for(int i=0;i<ilerazy;i++){
        auto t1=Clock::now();
        usunpocz();
        auto t2=Clock::now();
        time+=std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();

    }
    time=time/ilerazy;
    cout <<"sredni czas to:"<< time << " ms.\n";
}