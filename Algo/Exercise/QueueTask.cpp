// p64 exercise 
#include "../DataStructure/Queue.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    int taskNum, oneTime;
    cin >> taskNum >> oneTime;
    ArrQueue taskQueue;
    string tName;
    int tTime;
    for (int i = 0; i < taskNum; i++)
    {
        cin >> tName >> tTime;

        Task task(tName, tTime);
        taskQueue.enqueue(task);
    }
    int currentTime = 0;
    while (!taskQueue.isEmpty()) {
        Task topTask = taskQueue.dequeue();
        if (topTask.time <= oneTime) {
            currentTime += topTask.time;
            cout << topTask.name << " " << currentTime << endl;
        } else {
            topTask.time -= oneTime;
            taskQueue.enqueue(topTask);
            currentTime += oneTime;
        }

    }
    
    return 0;
}