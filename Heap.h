//
// Created by Eden Bar on 01/01/2023.
//

#ifndef MTA_ROADBRIDGES_HEAP_H
#define MTA_ROADBRIDGES_HEAP_H

#include <iostream>

typedef struct {
    int key;
    int value;
} Pair;

class Heap {
    
    Pair* _data; // Points to data array
    int _maxSize; // Max size of the heap
    int _heapSize; // Current size of the heap
    int _allocated; // 1 if the heap is allocated, 0 otherwise
    
    static int left(int node);
    static int right(int node);
    static int parent(int node);
    void FixHeap(int node);
    
public:
    
    Heap(int maxSize); // allocate memory
    Heap(Pair A[], int size); // Turn A[] into a heap
    ~Heap();
    void Insert(Pair pair);
    Pair DeleteMax();
    void Print();
    void HeapSort(Pair A[], int size);
};


#endif //MTA_ROADBRIDGES_HEAP_H
