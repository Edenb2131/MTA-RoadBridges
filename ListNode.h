//
// Created by Eden Bar on 08/01/2023.
//

#ifndef MTA_ROADBRIDGES_LISTNODE_H
#define MTA_ROADBRIDGES_LISTNODE_H

#include <iostream>
#include "Heap.h"

class ListNode {

    Pair* _pair;
    ListNode* _next;
    
public:
    
    ListNode();
    ListNode(Pair* h);
    ~ListNode();
    float getHeight();
    ListNode* getNext();
    Pair* getPair();
    void setPair(Pair* p);
    void setNext(ListNode* next);
    ListNode* createNewListNode(Pair p , ListNode* next);
    
};



#endif //MTA_ROADBRIDGES_LISTNODE_H
