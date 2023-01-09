//
// Created by Eden Bar on 01/01/2023.
//

#ifndef MTA_ROADBRIDGES_HEAP_H
#define MTA_ROADBRIDGES_HEAP_H

#include <iostream>
#define HAVE_NO_BRIDGES -1

struct Pair {
    float _height;
    int _road;
    
    Pair() {
        _height = 0;
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
    void FixHeap(Pair* node);
    Pair* getData(int i);
    Heap(int maxSize); // allocate memory
    ~Heap();
    void Insert(Pair* a);
    void Print();
    int getSize() const{
        return _heapSize;
    }
    int getPairPos(Pair* p);
};


#endif //MTA_ROADBRIDGES_HEAP_H
