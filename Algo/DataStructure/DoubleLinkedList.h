#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

struct Node
{
    int val;
    Node* prev;
    Node* next;
    Node() { val = 0; prev = nullptr; next = nullptr; }
    Node(int val) { val = val; prev = nullptr; next = nullptr; }
};

class DoubleLinkedList
{ 
private:
    Node* nil; // the node before first valid node 
public: 
    DoubleLinkedList();
    DoubleLinkedList(int val);
    ~DoubleLinkedList();
    void insert(int val);
    void deleteKey(int val);
    void deleteNode(Node* node);
    void deleteFirst();
    void deleteLast();
    Node* findNode(int val);
};


#endif