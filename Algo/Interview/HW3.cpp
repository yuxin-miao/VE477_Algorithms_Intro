#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
  // INPUT
  string str;
  stringstream ss;
  int taskNum;
  int staffNum;
  int internNum, internWork;
  cin >> taskNum;
  vector<int> tasks(taskNum, 0);

  getline(cin, str);
  getline(cin, str);
  ss << str;
  
  for (int i = 0; i < taskNum; i++)
  {
    int temp;
    ss >> temp;
    tasks[i] = temp;
  }
  string str2;
  stringstream ss2;
  cin >> staffNum;
  vector<int> staff(staffNum, 0);

  getline(cin, str2);
  getline(cin, str2);
  ss2 << str2;
  for (int i = 0; i < staffNum; i++)
  {
    int temp;
    ss2 >> temp;
    staff[i] = temp;
  }
  cin >> internNum >> internWork;
  const int interNumct = internNum;
  // CALCULATION
  int taskFinish = 0;
  int taskPtr = 0;
  sort(tasks.begin(), tasks.end(), less<int>());
  sort(staff.begin(), staff.end(), less<int>());
  for (int i = 0; i < staffNum; i++)
  {
    if (taskPtr >= taskNum) break;
    while (true) {
      if (staff[i] >= tasks[taskPtr]) {
        taskFinish++;
        taskPtr++;
        break;
      } else if (internNum > 0 && (staff[i] + internWork >= tasks[taskPtr])) {
        internNum--;
        taskFinish++;
        taskPtr++;
        break;
      } else taskPtr++;
    }
  }
  int taskFinish2 = 0;
  taskPtr = 0;
  internNum = interNumct;
  sort(tasks.begin(), tasks.end());
  sort(staff.begin(), staff.end());
  for (int i = 0; i < staffNum; i++)
  {
    if (taskPtr >= taskNum) break;
    while (true) {
      if (staff[i] >= tasks[taskPtr]) {
        taskFinish2++;
        taskPtr++;
        break;
      } else if (internNum > 0 && (staff[i] + internWork >= tasks[taskPtr])) {
        internNum--;
        taskFinish2++;
        taskPtr++;
        break;
      } else taskPtr++;
    }
  }
  taskFinish = max(taskFinish2, taskFinish);
  // OUTPUT
  cout << taskFinish << endl;
  return 0;
}