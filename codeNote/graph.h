//
// Created by 于欣淼 on 2020/9/18.
//

#ifndef CODENOTE_GRAPH_H
#define CODENOTE_GRAPH_H

#include <iostream>
#include <vector>

using namespace std;
// adjacency list representation for graph
template <class T>
class Node {
    T value;
    Node* next;
};

template <class T>
class Graph {
    vector<pair<T, int>> adj[2]; // initialize the size of array as 2
    int Vnum;
    void growth(); // make the array bigger
public:
    explicit Graph(int size = 2);
    void addNode(T value);
    void addEdge(T value1, T value2, int wt);

    ~Graph();
};

template<class T>
Graph<T>::Graph(int size):Vnum(size) {
}

template<class T>
Graph<T>::~Graph() {


}

template<class T>
void Graph<T>::addNode(T value) {
    auto* newNode = new Node<T>;
    newNode->value = value;
    newNode->next = nullptr;
}

template<class T>
void Graph<T>::addEdge(T value1, T value2, int wt) {
    bool add1 = false, add2 = false;
    for (int i = 0; i < Vnum; i++) {
        if (adj[i].first == value1) {
            adj[i].push_back(make_pair(value2, wt));
            add1 = true;
        }
        else if (adj[i].first == value2) {
            adj[i].push_back(make_pair(value1, wt));
            add2 = true;
        }
    }
    if (!add1) {
        adj[Vnum] = value1;
        adj[Vnum].push_back(make_pair(value2, wt));
        Vnum++;
    }
    if (!add2) {
        adj[Vnum] = value2;
        adj[Vnum].push_back(make_pair(value1, wt));
        Vnum++;
    }


}

template<class T>
void Graph<T>::growth() {
    auto* bigAdj = new vector<pair<T, int>>[2 * Vnum];


}

#endif //CODENOTE_GRAPH_H
