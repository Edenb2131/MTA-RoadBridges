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

//Heap::Heap(Pair A[], int size) {
//    _data = A; /////// check
//    _maxSize = size;
//    _heapSize = size;
//    _allocated = 0; // The heap is not allocated
//
//    for (int i = (size / 2) - 1 ; i >= 0; i--) {
//        FixHeap(i);
//    }
//}

Heap::~Heap() {
//    if (_allocated) {
//        for(int i = 0; i < _heapSize; i++) {
//            if(_data[i] != nullptr) {
//                delete _data[i];
//            }
//        }
//        delete[] _data;
//    }
//    _data = nullptr;
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

void Heap::Insert(Pair* a) {
    if (_heapSize == _maxSize) {
        _maxSize*=2;
    }
    _data[_heapSize] = a;
    
    int i = _heapSize;
    while (i > 0 && _data[parent(i)]->_height < _data[i]->_height) {
        Pair* temp = _data[i];
        _data[i] = _data[parent(i)];
        _data[parent(i)] = temp;
        i = parent(i);
    }
    _heapSize++;
    
}


void Heap::Print() {
    for (int i = 0; i < _heapSize; i++) {
        cout << _data[i]->_height << " ";
    }
    cout << endl;
}


// Fix heap for max heap
void Heap::FixHeap(Pair* node) {
    // Add the new pair to the end of the array happens before

//    // Fix the heap starting at the new pair's parent
//    int current = getPairPos(node) ;
//    while (current >= 0) {
//        // Get the left and right children of the current node
//        int left = 2 * current + 1;
//        int right = 2 * current + 2;
//
//        // Find the largest of the three values (current node, left child, right child)
//        int largest = current;
//        if (left > _heapSize && _data[left]->_height > _data[largest]->_height) {
//            largest = left;
//        }
//        if (right > _heapSize && _data[right]->_height > _data[largest]->_height) {
//            largest = right;
//        }
//
//        // If the largest value is not the current node, swap the values and continue
//        if (largest != current) {
//            Pair* temp = _data[current];
//            _data[current] = _data[largest];
//            _data[largest] = temp;
//            current = largest;
//        } else {
//            break;
//        }
//    }





    int max;
    int current = getPairPos(node) ;
    int left = 2 * current + 1;
    int right = 2 * current + 2;

    if(left < _heapSize && _data[left]->_height > _data[current]->_height){
        max = left;
    } else {
        max = current;
    }
    if(right < _heapSize && _data[right]->_height > _data[max]->_height){
        max = right;
    }

    if(max != current){
        Pair* temp = _data[current];
        _data[current]->_height = _data[max]->_height;
        _data[current]->_road = _data[max]->_road;

        _data[max]->_height = temp->_height;
        _data[max]->_road = temp->_road;


        FixHeap(_data[max]);
    }





    
//    int i = getPairPos(node);
//    int l = left(i);
//    int r = right(i);
//    int max = i;
//
//    if (l < _heapSize && (_data[l]->getMinBridge() == HAVE_NO_BRIDGES || _data[l]->getMinBridge() > _data[i]->getMinBridge() )) { // if the left child is bigger than the parent
//        max = l;
//    }
//    if (r < _heapSize && ( _data[r]->getMinBridge() > _data[max]->getMinBridge() ||  _data[r]->getMinBridge() == HAVE_NO_BRIDGES)) { // if the right child is bigger than the parent
//        max = r;
//    }
//    if (max != i) { // if the parent is not the biggest
//        Pair *temp = _data[i];
//        int temp_heap_place = getPairPos(_data[i]);
//        int temp_heap_place2 = getPairPos(_data[max]);
//        _data[i] = _data[max];
//        _data[i]->getRoad()->setHeapPlace(temp_heap_place);
//        _data[max] = temp;
//        _data[max]->getRoad()->setHeapPlace(temp_heap_place2);
//
//
//        FixHeap(max);
//    }
//
//
    
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


