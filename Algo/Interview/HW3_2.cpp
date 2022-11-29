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

  // CALCULATION
  // each slot DP[i][j][0] represents staff[i] didn't use intern for task[j], the max finished task number
  // slot DP[i][j][1] represents staff[i] used intern for task[j], the max finished task number
  // DP[i][j][2] = number of used intern
  int taskFinish = 0;
  int taskPtr = 0;
  vector< vector< vector<int> > > DPTable(staffNum, vector< vector<int> >(taskNum, vector<int>(3, 0)));
  for (int j = 0; j < taskNum; j++)
  {
    if (staff[0] >= task[j]) DPTable[0][j][0] = 1;
    else if (staff[0] + internWork >= task[j]) {DPTable[0][j][1] = 1; DPTable[0][j][2]++;}
  }
  for (int i = 1; i < staffNum; i++)
  {
    for (int j = 0; j < taskNum; j++)
    {
      if (staff[0] >= task[j]) DPTable[i][j].first = 1;
      else if (staff[0] + internWork >= task[j]) {DPTable[0][j].second = 1; DPTable[0][j][2]++;}
    }
    
  }
    

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
  // OUTPUT
  cout << taskFinish << endl;
  return 0;
}