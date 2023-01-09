//
// Created by Eden Bar on 08/01/2023.
//

#include "List.h"
using namespace std;

List::List(){
    init();
}

List::~List() {
    ListNode* curr = _head;
    while(curr != nullptr) {
        ListNode* temp = curr;
        curr = curr->getNext();
        delete temp;
    }
    _head = nullptr;
    _tail = nullptr;
     delete _min;
}

void List::init() {
    _head = nullptr;
    _tail = nullptr;
    _min = new ListNode();
    _size = 0;
    IsEmpty = true;
}

void List::add(float h, int r, bool& neededToFixHeap) {
    Pair* p = new Pair(h, r);
    insertToEndList(this, p);
    
    if (h < _min->getHeight()) {
        _min->setPair(_tail->getPair());
        neededToFixHeap = true;
    }
    
    _size++;
}

void List::print() {
    ListNode* node = _head;
    while (node != nullptr) {
        cout << node->getHeight() << "  ";
        node = node->getNext();
    }
    cout << endl;
}

Pair* List::getMin() {
    return _min->getPair();
}

void List::insertToEndList(List *lst, Pair* p) {
    ListNode* newTail;
    newTail = lst->_tail->createNewListNode(*p, nullptr);
    insertNodeToEndList(lst, newTail);
    
}

void List::insertNodeToEndList(List *pList, ListNode *pNode) {
    
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




