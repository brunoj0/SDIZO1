//
// Created by brunoj on 04.03.17.
//

#ifndef SDIZO_1_BINARYHEAP_H
#define SDIZO_1_BINARYHEAP_H
#include <iostream>

class binaryheap {
public:
    binaryheap();
    void createRandom(int);
    void addElement(int);
    void search(int);
    void deleteElement(int);
    void print();
    void FromFile(std::string);

    void testDel(int, int);
    void testAdd(int, int);
private:
    int *tablica;
    int *bufor;
    int size;

    int left(int);
    int right(int);
    int parent(int);
    void CheckToDown(int);
    void ChceckBot(int);
};


#endif //SDIZO_1_BINARYHEAP_H
