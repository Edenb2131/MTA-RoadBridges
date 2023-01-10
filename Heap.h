//
// Created by Eden Bar on 01/01/2023.
//

#ifndef MTA_ROADBRIDGES_HEAP_H
#define MTA_ROADBRIDGES_HEAP_H

#include <iostream>
#define HAVE_NO_BRIDGES 10000

struct Pair {
    float _height = HAVE_NO_BRIDGES;
    int _road = -1;
    int _index = -1;

    Pair() {
        _height = HAVE_NO_BRIDGES;
        _road = 0;
    }

    Pair(float h, int r) {
        _height = h;
        _road = r;
    }

};


// this will be min heap
class Heap {

    Pair** _data; // Points to data array
    int _maxSize; // Max size of the heap
    int _heapSize; // Current size of the heap
    int _allocated; // 1 if the heap is allocated, 0 otherwise

    static int left(int node);
    static int right(int node);
    static int parent(int node);


public:
    void FixHeap(int node);
    Pair* getData(int i);
    Heap(int maxSize); // allocate memory
    ~Heap();
    void Insert(Pair* item);
    void Print();
    int getPairPos(Pair* p);
    int getSize() const {
        return _heapSize;
    }

};


#endif //MTA_ROADBRIDGES_HEAP_H