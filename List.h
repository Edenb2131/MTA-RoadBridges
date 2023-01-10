#ifndef MTA_ROADBRIDGES_LIST_H
#define MTA_ROADBRIDGES_LIST_H

#include <iostream>
#include "ListNode.h"

class List {
    ListNode* _head;
    ListNode* _tail;
    ListNode* _min;
    int _size;


public:
    bool IsEmpty = true;
    List();
    ~List();
    void init();
    void add(float h, int r, bool& neededToFixHeap);
    void print();
    Pair* getMin();
    void insertToEndList(List* lst, Pair* p);
    void insertNodeToEndList(List* pList, ListNode* pNode);
};


#endif //MTA_ROADBRIDGES_LIST_H