//
// Created by Eden Bar on 01/01/2023.
//

#include "Heap.h"
using namespace std;


Heap::Heap(int maxSize) {
    _data = new Pair*[maxSize];
    _maxSize = maxSize;
    _heapSize = 0;
    _allocated = 1;
}


Heap::~Heap() {
    if (_allocated) {
        delete[] _data;
    }
}

// private functions of Heap class

int Heap::left(int node) {
    return 2 * node + 1;
}

int Heap::right(int node) {
    return (2 * node + 2);
}

int Heap::parent(int node) {
    return (node - 1) / 2;
}


// public functions of Heap class

void Heap::Insert(Pair* item) {
    if (_heapSize == _maxSize) {
        _maxSize *= 2;
        cout << "Heap is full" << endl;
//        throw "Heap is full !";
    }
    int i = _heapSize;
    _heapSize++;
    
    while (i > 0 && _data[parent(i)]->_height < item->_height) {
        _data[i] = _data[parent(i)];
        _data[i]->_index = i;
        i = parent(i);
    }
    _data[i] = item;
    _data[i]->_index = i;
    
}


void Heap::Print() {
    for (int i = 0; i < _heapSize; i++) {
        cout << _data[i]->_height << " ";
    }
    cout << endl;
}


// Fix heap for max heap
void Heap::FixHeap(int node) {
    int max;
    int Left = left(node);
    int Right = right(node);

    if (Left < _heapSize && _data[Left]->_height > _data[node]->_height) {
        max = Left;
    }
    else {
        max = node;
    }
    if (Right < _heapSize && _data[Right]->_height > _data[max]->_height) {
        max = Right;
    }

    if (max != node) {
        swap(_data[node], _data[max]);
        int temp = _data[node]->_index;
        _data[node]->_index = _data[max]->_index;
        _data[max]->_index = temp;
        FixHeap(max);
    }

    
    
}

Pair* Heap::getData(int i) {
    return _data[i];
}

int Heap::getPairPos(Pair *p) {
    for (int i = 0; i < _heapSize; i++) {
        if (_data[i] == p) {
            return i;
        }
    }
    return -1;
}


