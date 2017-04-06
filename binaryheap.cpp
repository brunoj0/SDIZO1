//
// Created by brunoj on 04.03.17.
//

#include "binaryheap.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
binaryheap::binaryheap() {
    size=0;
    tablica=new int[size];
}
int binaryheap::parent(int i){
    return(i - 1) / 2;

}
int binaryheap::left(int i){
    return(i * 2) + 1;

}

int binaryheap::right(int i){
    return(i * 2) + 2;

}

void binaryheap::search(int element) {
    bool znaleziony=false;
    int i=0;
    for(int i=0;i<size;i++) {
        if (element == tablica[i]) {
            znaleziony = true;

        }
    }
    if(tablica[i]==element){
        cout<<"w kopcu znajduje sie element :"<<element<<endl;
    }else{
        cout<<"elemenut: "<<element<<" nie ma w tablica"<<endl;
    }
}

void binaryheap::deleteElement( int a) {

    if(size!=0){
        if(a==size-1){
            size-=1;
        }else{
        for(int i=0;i<size;i++){
            if(a==tablica[i]){
                tablica[i]=tablica[size-1];
                CheckToDown(i);
                size-=1;

            }
        }
        }

    }else{
        cout<<"wielkosc kopca jest rowna 0"<<endl;
    }

}
//              10
//      ||--------------||
//       6               8
//  ||------||      ||------||
//   2       4       3       6
//||--||  ||--||  ||--||  ||--||
// 0   1   3   2   2   1   0   2
void binaryheap::print() {

if(size==0){
    cout<<"brak elementow do wyswietlenia"<<endl;
    return;
}
cout<<setw(40)<<tablica[0]<<endl<<endl;
    for(int i=1;i<3;i++) {
        if(size>i) {
            cout << setw(27);
            if(tablica[i] != 0)
            cout << tablica[i];
            else
            cout << 'x';
        }
    }
    cout<<endl<<endl;
    for(int i=3;i<7;i++) {
        if(size>i) {
            cout << setw(16);
            if(tablica[i] != 0)
                cout << tablica[i];
            else
                cout << 'x';
        }
    }
    cout<<endl<<endl;
    for(int i=7;i<16;i++) {
        if(size>i) {
            cout << setw(9);
            if(tablica[i] != 0)
                cout << tablica[i];
            else
                cout << 'x';    ;
        }
    }
    cout<<endl<<endl;
}


void binaryheap::CheckToDown(int del){
    int tmp;
    while(tablica[del]<tablica[left(del)] ||tablica[del]<tablica[right(del)] ){
        tmp=tablica[del];
        if(tablica[right(del)]<tablica[left(del)]) {
            tablica[del] = tablica[left(del)];
            tablica[left(del)] = tmp;
        }else{
            tablica[del] = tablica[right(del)];
            tablica[right(del)] = tmp;
        }
        del=left(del);
        }


}
//sortuje od ostatiego elementu do gory
void binaryheap::ChceckBot(int a) {
    if(a==1){
        return;
    }
    int bufor=a-1;
    int parbuf=parent(bufor);
    int tmp;
    while(tablica[bufor]>tablica[parbuf]){
        tmp=tablica[parbuf];
        tablica[parbuf]=tablica[bufor];
        tablica[bufor]=tmp;
        bufor=parbuf;
        parbuf=parent(parbuf);

    }
}


void binaryheap::FromFile(std::string path) {


    fstream plik;
    string bufor;
    int var;
    plik.open( path.c_str(), std::ios::in);
    getline(plik,bufor);
    int help=stoi(bufor);
    for(int i=0;i<help;i++){
        getline(plik,bufor);
        var=stoi(bufor);
        addElement(var);
    }
}
void binaryheap::addElement(int element) {
    bufor=new int[size+1];
    for(int i=0; i<size;i++){
        bufor[i]=tablica[i];
    }
    bufor[size]=element;
    size=size+1;
    tablica=new int[size];
    tablica=bufor;
    ChceckBot(size);


}

void binaryheap::createRandom(int size) {
    srand( time( NULL ) );
    this->size=size;
    for(int i=0;i<size;i++){
        addElement(rand()%1000);
    }

}