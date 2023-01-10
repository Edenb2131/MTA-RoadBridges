//
// Created by Eden Bar on 08/01/2023.
//

#ifndef MTA_ROADBRIDGES_ROADS_H
#define MTA_ROADBRIDGES_ROADS_H

#include <iostream>
#include "Heap.h"
#include "List.h"

#define HAVE_NO_BRIDGES 10000

class Roads {
    List* _roads;
    int _size;
    Heap _heap;


public:

    Roads(int size);
    ~Roads();
    void init();
    void print();
    void addBridge(float h, int r);
    void whichRoad(float h);
    void print(int r);


};


#endif //MTA_ROADBRIDGES_ROADS_H