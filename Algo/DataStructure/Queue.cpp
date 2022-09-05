using namespace std;
#define MAX 1000
class QueueFullOrEmpty{};

class ArrQueue {
    int head;
    int tail;
    int Queue[MAX];
public:
    ArrQueue() { head = tail = 0; }
    bool isFull();
    bool isEmpty();
    void enqueue(int val);
    int dequeue();
};

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

void ArrQueue::enqueue(int val) {
    if (isFull()) throw QueueFullOrEmpty();
    Queue[tail] = val;
    tail = CircularAddOne(tail);
}

int ArrQueue::dequeue() {
    if (isEmpty) throw QueueFullOrEmpty();
    int val = Queue[head];
    head = CircularAddOne(head);
    return val;
}