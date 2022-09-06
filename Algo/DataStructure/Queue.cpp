#include "Queue.h"
#include <string>
using namespace std;

ArrQueue::ArrQueue() { head = tail = 0; }
bool ArrQueue::isEmpty() {
    return head == tail;
}

bool ArrQueue::isFull() {
    return head == (tail + 1) % MAX;
}

int CircularAddOne(int num) {
    if (num + 1 == MAX) return 0;
    else return num + 1;
}

void ArrQueue::enqueue(Task val) {
    if (isFull()) throw QueueFullOrEmpty();
    Queue[tail] = val;
    tail = CircularAddOne(tail);
}

Task ArrQueue::dequeue() {
    if (isEmpty()) throw QueueFullOrEmpty();
    Task val = Queue[head];
    head = CircularAddOne(head);
    return val;
}