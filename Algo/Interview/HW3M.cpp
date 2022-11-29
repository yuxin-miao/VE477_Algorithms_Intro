#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
/**
 * @brief 11.23 HW机考第三题 300pt
 * 输入几个工作，每个工作需要的工作量
 * 输入几个员工，每个员工可以完成的工作量
 * 输入有X个实习生，每个实习生可以完成的工作量Y
 * 每个员工最多可以有一个实习生辅助
 * 输出最多能有多少个工作被完成
 * @return int
 */

int main() {
    // INPUT
    int taskNum;
    int staffNum;
    int internNum, internWork;
    int tmp;
    vector<int> tasks, staff;
    vector<int> remainTasks, remainStaff;

    cin >> taskNum;
    for (int i = 0; i < taskNum; i++) {
        cin >> tmp;
        tasks.push_back(tmp);
    }

    cin >> staffNum;
    for (int i = 0; i < staffNum; i++) {
        cin >> tmp;
        staff.push_back(tmp);
    }

    cin >> internNum >> internWork;

    sort(tasks.begin(), tasks.end(), less<int>());
    sort(staff.begin(), staff.end(), less<int>());

    // CALCULATION
    int taskFinish = 0;
    int taskPtr = 0;
    int staffPtr = 0;

    // Pick staff can finish task alone first
    while (taskPtr < tasks.size() && staffPtr < staff.size()) {
        if (staff[staffPtr] >= tasks[taskPtr]) {
            staffPtr++;
            taskPtr++;
            taskFinish++;
        } else {
            remainStaff.push_back(staff[staffPtr]);
            staffPtr++;
        }
    }

    while (taskPtr < tasks.size()) {
        remainTasks.push_back(tasks[taskPtr]);
        taskPtr++;
    }
    while (staffPtr < staff.size()) {
        remainStaff.push_back(staff[staffPtr]);
        staffPtr++;
    }

    taskPtr = 0;
    staffPtr = 0;

    // See if remained staff can finish task with help of intern
    while (taskPtr < remainTasks.size() && staffPtr < remainStaff.size()) {
        if (internNum > 0 &&
            (remainStaff[staffPtr] + internWork >= remainTasks[taskPtr])) {
            staffPtr++;
            taskPtr++;
            internNum--;
            taskFinish++;
        } else {
            staffPtr++;
        }
    }

    cout << taskFinish << endl;
    return 0;
}