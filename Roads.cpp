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

//Roads::~Roads() {
//    delete[] _roads;
//}

void Roads::init() {
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

    if (_roads[r].IsEmpty) {
        _heap.Insert(_roads[r].getMin());
        // No need for fix heap as it's happening in insert
        _roads[r].IsEmpty = false;
    }

    if (neededToFixHeap)
        _heap.FixHeap(_roads[r].getMin()->index);


}

void Roads::whichRoad(float h) {

    if (_size - 1 == 0) {
        cout << 0;
    }

    else if (h > _heap.getData(0)->_height) {
        cout << "No road" << endl;
    }

    else {
        cout << (_heap.getData(0))->_road << endl;
    }

}

void Roads::print(int r) {
    _roads[r].print();
}



