//
// Created by Eden Bar on 08/01/2023.
//

#include "Roads.h"
using namespace std;

#define NO_ROADS 0

Roads::Roads(int size) : _heap(size) {
    _size = size;
    _roads = new List[size];
}

Roads::~Roads() {
    delete[] _roads;
}

void Roads::init() {
    for (int i = 0; i < _size; i++) {
        _roads[i].init();
        _roads[i].getMin()->_road = i;
        _roads[i].getMin()->_index = i;
    }
    
    for(int i = 1; i < _size; i++)
        _heap.Insert(_roads[i].getMin());
    
}

void Roads::print() {
    for (int i = 0; i < _size; i++) {
        cout << "Road " << i << ": ";
        _roads[i].print();
    }
}

void Roads::addBridge(float h, int r) {
    bool neededToFixHeap = false;
    _roads[r].add(h, r, neededToFixHeap);
    
    // As we started the heap to be with all the min, we will update everytime we add a new bridge
    _heap.FixHeap(_roads[r].getMin()->_index);
    

}

void Roads::whichRoad(float h) {

//    // Print all the roads:
//    print();
//
//    cout << endl;
//
//    // Print the heap:
//    cout << "Heap " <<  ": ";
//    for (int i = 0; i < _heap.getSize(); i++) {
//        cout << _heap.getData(i)->_height << "  ";
//    }
//
//    cout << endl;
//
    if (_size - 1 == 0) {
        cout << 0;
    }
    
    else if (h > _heap.getData(0)->_height) {
        cout << NO_ROADS << endl;
    }

    else {
        cout << (_heap.getData(0))->_road << endl;
    }
}

void Roads::print(int r) {
    _roads[r].print();
}



