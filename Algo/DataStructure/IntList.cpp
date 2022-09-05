#include "IntList.h"
#include<iostream>


bool IntList::isEmpty() const {
    return !first;
}

void IntList::insert(int v) {
    Node* newNode = new Node;
    newNode->num = v;
    newNode->next = first;
    first = newNode;
}

int IntList::remove() {
    if(isEmpty()) {
        throw listIsEmpty();
    }
    Node* victim = first;
    first = victim->next;
    // Remember to delete the pointer 
    int val = victim->num;
    delete victim;
    return val;
}

int &IntList::head() {
    if(isEmpty()) throw listIsEmpty();
    return first->num;
}

void IntList::print() const{
    Node* printNode = first;
    while (printNode)
    {
        std::cout << printNode->num << " ";
        printNode = printNode->next;
    }
    std::cout << std::endl;
}

IntList::IntList(): first(0){
}
void IntList::removeAll() {
    while(!isEmpty()) {
        remove();
    }
}

IntList::~IntList() {
    removeAll();
}

void IntList::copyList(Node *list) {
/*     first = new Node;
    first->num = list->num;
    first->next = list->next;
    Node* copyNode = list->next;
    Node* prevNode = first;
    while(copyNode) {
        Node* tempNode = new Node;
        tempNode->num = copyNode->num;
        tempNode->next = copyNode->next;
        prevNode->next = tempNode;
        prevNode = tempNode;
        copyNode = copyNode->next;
    } */
    if(!list) return;
    copyList(list->next);
    insert(list->num);
}

IntList::IntList(const IntList& l) {
    copyList(l.first);
}
IntList &IntList::operator=(const IntList &l) {
    if (this != &l)
    {
        removeAll();
        copyList(l.first);
    }
    return *this;
}