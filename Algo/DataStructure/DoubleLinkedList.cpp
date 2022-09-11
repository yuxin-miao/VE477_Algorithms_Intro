#include "DoubleLinkedList.h"
using namespace std;

DoubleLinkedList::DoubleLinkedList()
{
    Node* nil = new Node();
}

DoubleLinkedList::DoubleLinkedList(int val)
{
    Node* nil = new Node();
    Node* newNode = new Node(val);
    nil->next = newNode;
    newNode->prev = nil;
}
DoubleLinkedList::~DoubleLinkedList()
{

}

void DoubleLinkedList::insert(int val) {
    
}