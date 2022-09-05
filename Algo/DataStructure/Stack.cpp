// stack using IntList
#include"IntList.h"
#include<iostream>
#include<sstream>

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
using namespace std;

#define MAX 10000

class StackOverflow{};

class ArrStack {
    int top;
    char stack[MAX];
public:
    ArrStack() { top = 0; }
    bool isEmpty() { return top == 0; }
    bool isFull() { return top >= MAX - 1; }
    void push(char val);
    char pop();
};

void ArrStack::push(char val) {
    if (isFull()) throw StackOverflow(); 
    top++;
    stack[top] = val;
}

char ArrStack::pop() {
    if (isEmpty()) return NULL;
    char val = stack[top];
    top--;
    return val;
}

class IntStack{
    IntList l;
    int n;
public:
    IntStack():l(), n(0){};
    bool isEmpty() {
        return n==0;
    }
    int size() {return n;}
    void push(int val) {
        l.insert(val);
        n++;
    }
    int pop() {
        n--;
        return l.remove();
    }
    int& top() {return l.head();}
};

void main() {
	string line;
	cout << "Enter one Reversed Polish Expression" << endl;
	getline(cin, line);
	IntStack stack;

	
}