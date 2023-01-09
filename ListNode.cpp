//
// Created by Eden Bar on 08/01/2023.
//

#include "ListNode.h"

ListNode::ListNode() {
    _pair = new Pair();
    _pair->_height = 0;
    _pair->_road = 0;
    _next = nullptr;
    
}

ListNode::ListNode(Pair* h) {
    delete _pair;
    _next = nullptr;
}

ListNode::~ListNode() {

}

float ListNode::getHeight() {
    return _pair->_height;
}
ListNode* ListNode::getNext() {
    return _next;
}

void ListNode::setNext(ListNode* next) {
    _next = next;
}

void ListNode::setPair(Pair* p) {
    _pair->_height = p->_height;
    _pair->_road = p->_road;
}

Pair* ListNode::getPair() {
    return _pair;
}

ListNode* ListNode::createNewListNode(Pair p, ListNode *next) {
    
    ListNode* newNode = new ListNode();
    newNode->_pair = new Pair(p._height, p._road);
    newNode->_next = next;
    return newNode;
    
}





