//
// Created by Eden Bar on 01/01/2023.
//

#include "Heap.h"
using namespace std;

Heap::Heap(int maxSize) {
    _data = new Pair[maxSize];
    _maxSize = maxSize;
    _heapSize = 0;
    _allocated = 1;
}

Heap::Heap(Pair A[], int size) {
    _data = A;
    _maxSize = size;
    _heapSize = size;
    _allocated = 0; // The heap is not allocated
    
    for (int i = (size / 2) - 1 ; i >= 0; i--) {
        FixHeap(i);
    }
}

Heap::~Heap() {
    if (_allocated) {
        delete[] _data;
    }
    _data = nullptr;
}

// private functions of Heap class

int Heap::left(int node) {
    return (2 * node + 1);
}

int Heap::right(int node) {
    return (2 * node + 2);
}

int Heap::parent(int node) {
    return (node - 1) / 2;
}


void Heap::FixHeap(int node) {
    int max;
    int left = Heap::left(node);
    int right = Heap::right(node);
    
    if (left < _heapSize && _data[left].key > _data[node].key) {
        max = left;
    }
    else {
        max = node;
    }
    
    if (right < _heapSize && _data[right].key > _data[max].key) {
        max = right;
    }
    if (max != node) {
        // Swap values if necessary and fix heap
        Pair temp = _data[node];
        _data[node] = _data[max];
        _data[max] = temp;
        
        FixHeap(max);
    }
}

// public functions of Heap class

void Heap::Insert(Pair pair) {
    if (_heapSize == _maxSize) {
        cout << "Heap is full" << endl;
        // throw ??? ////////////////////////////////////////////
        return;
    }
    
    int node = _heapSize;
    _heapSize++;
    
    while (node > 0 && _data[parent(node)].key > _data[node].key) {
        _data[node] = _data[parent(node)];
        node = parent(node);
    }
    _data[node] = pair;
}

Pair Heap::DeleteMax() {
    if (_heapSize == 0) {
        cout << "Heap is empty" << endl;
        // throw ??? ////////////////////////////////////////////
        return {0, 0};
    }
    
    Pair max = _data[0];
    _data[0] = _data[_heapSize - 1];
    _heapSize--;
    FixHeap(0);
    
    return max;
}

void Heap::Print() {
    for (int i = 0; i < _heapSize; i++) {
        cout << _data[i].key << " ";
    }
    cout << endl;
}


void Heap::HeapSort(Pair A[], int size) {
   Heap H(A, size);
   Pair item;
   
   for (int i = size - 1; i >= 0; i--) {
         item = H.DeleteMax();
         A[i] = item;
   }
}

