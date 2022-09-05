#ifndef INTLIST_H
#define INTLIST_H
class listIsEmpty{};
// single-linked list contains only int 
struct Node
{
    int num;
    Node* next;
};
class IntList{
    Node *first;
    void removeAll();
    void copyList(Node *list);

public:
    bool isEmpty() const;
    // EFFECTS: returns true if list is empty, false otherwise
    void insert(int v);
    // MODIFIES: this
    // EFFECTS: inserts v into the front of the list
    int remove();
    // MODIFIES: this
    // EFFECTS: if list is empty, throw listIsEmpty.
    //          Otherwise, remove and return the first 
    //          element of the list
    int &head();
    // EFFECTS: return the value in the first node if it exists
    //          Otherwise, throw listIsEmpty
    void print() const;
    // MODIFIES: cout
    // EFFECTS: print the int list

    IntList();
    // default constructor
    IntList(const IntList& l);
    // copy constructor
    ~IntList();
    // destructor
    IntList &operator=(const IntList &l); 
    // assignment operator
};


#endif