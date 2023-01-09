//
// Created by Eden Bar on 08/01/2023.
//

#include "Roads.h"
using namespace std;

Roads::Roads(int size) : _heap(1) {
    _size = size;
    _roads = new List[size];
    _roads->init();
}

Roads::~Roads() {
    delete[] _roads;
}

void Roads::init(){
    for (int i = 0; i < _size; i++) {
        _roads[i].init();
    }
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
    
    if(_roads[r].IsEmpty) {
        _heap.Insert(_roads[r].getMin());
        // No need for fix heap as it's happening in insert
        _roads[r].IsEmpty = false;
    }
    
    if(neededToFixHeap)
        _heap.FixHeap(_heap.getData(_heap.getSize() -1));
    
    
    // This mean h > _roads[r].getMin()._height and we dont need him in the heap
    
}

void Roads::whichRoad(float h) {
    
//    _heap.FixHeap(_heap.getData(_heap.getSize() - 1));

    // print all the roads
    for (int i = 1; i < _size; i++) {
        cout << "Road " << i << ": ";
        _roads[i].print();
    }
    cout << endl;
    
    // print the heap
    cout << "heap :  " ;
    for(int i = 0; i < _heap.getSize(); i++) {
        cout << _heap.getData(i)->_height << " ";
    }
    cout << endl;
    
    if(h > _heap.getData(0)->_height) {
        cout << "No road" << endl;
    }
    
    else {
        cout << _heap.getData(0)->_road << endl;
    }
    
}

void Roads::print(int r) {
      _roads[r].print();
}




