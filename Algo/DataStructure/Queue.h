#ifndef QUEUE_H
#define QUEUE_H
#define MAX 1000

#include <string>
class QueueFullOrEmpty{};

struct Task
{
    std::string name;
    int time;
    Task() {name = ""; time = 0; }
    Task(std::string n, int t) {name = n ; time = t;}
};


class ArrQueue {
    int head;
    int tail;
    Task Queue[MAX];
public:
    ArrQueue();
    bool isFull();
    bool isEmpty();
    void enqueue(Task val);
    Task dequeue();
};


#endif