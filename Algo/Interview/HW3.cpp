#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;
/**
 * @brief 11.23 HW机考第三题 300pt
 * 输入几个工作，每个工作需要的工作量
 * 输入几个员工，每个员工可以完成的工作量
 * 输入有X个实习生，每个实习生可以完成的工作量Y
 * 每个员工最多可以有一个实习生辅助
 * 输出最多能有多少个工作被完成
 * 
 * Example:
 * INPUT:
 * 3
 * 10 30 40 
 * 5
 * 5 10 20 20 5 
 * 2
 * 10
 * OUTPUT:
 * 2
 *  @return int 
 */

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