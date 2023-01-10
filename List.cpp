//
// Created by Eden Bar on 08/01/2023.
//

#include "List.h"
using namespace std;
#include <iomanip>

List::List() {
    init();
}

List::~List() {
    while (_head != nullptr) {
        ListNode* next = _head->getNext();
        delete _head;
        _head = next;
    }
    _tail = nullptr;
    delete _min;
    _min = nullptr;
}


void List::init() {
    _head = nullptr;
    _tail = nullptr;
    _min = new ListNode();
    _size = 0;
    IsEmpty = true;
}

void List::add(float h, int r, bool& neededToFixHeap) {
    if(_min->getPair()->_index == -1){
        neededToFixHeap = true;
    }
    
    Pair* p = new Pair(h, r);
    p->_index = -1; // This will never be min. Min is a pointer to the min in the heap and have an index.
    insertToEndList(this, p);

    if (h <= _min->getHeight()) {
        _min->setPair(_tail->getPair());
        neededToFixHeap = true;
    }
    _size++;
}

void List::print() {
    ListNode* node = _head;
    while (node != nullptr) {
        cout << std::fixed << std::setprecision(4) <<node->getHeight() ;
        node = node->getNext();
        if(node != nullptr)
            cout << ", ";
    }
    cout << endl;
}

Pair* List::getMin() {
    return _min->getPair();
}

void List::insertToEndList(List* lst, Pair* p) {
    ListNode* newTail;
    newTail = lst->_tail->createNewListNode(*p, nullptr);
    insertNodeToEndList(lst, newTail);

}

void List::insertNodeToEndList(List* pList, ListNode* pNode) {

    if (pList->_head == nullptr) {
        pList->_head = pNode;
        pList->_tail = pNode;
        
        pList->_min->setPair(pNode->getPair());
    }
    else {
        pList->_tail->setNext(pNode);
        pList->_tail = pNode;

    }

}



