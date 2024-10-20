#include <vector>
#include <iostream>
#include <sstream>
using namespace std;
/**
 * @brief 11.23 HW机考第二题 200pt
 * 四种颜色，每个房子刷每种颜色会花费不同的钱
 * 两个相邻的房子不能刷一样的颜色
 * 最少花多少钱刷完所有房子
 * @return int
 * 
 * 
 * c++ 智能指针，了解哪些，有什么区别 - 只说了auto 自动检测类型 更安全
 * shared ptr？sth
 * using c++11, c++17 ... 有什么不同，习惯用哪个
 * 说一下编译的时候全局变量 静态变量 还有其他各种 怎么存在内存中的
 * 栈 堆 ...以及其他的在编译时候怎么排布的
 * 对计算机网络的了解 五层有哪些
 * TCP UDP有什么区别 分别是什么
 * IP协议有什么用 没有IP协议直接用MAC地址会怎么样
 * 数据库不了解
 * 计算机系统
 * 还问了一些想不起起来的
 * .s .so ? 什么什么库
 */

int main() {
  // INPUT
  int n;
  cin >> n;
  vector< vector<int> > cost(n, vector<int>(4, 0));
  vector< vector<int> > DPTable(n, vector<int>(4, 0));
  string discard;
  getline(cin, discard);
  for (int i = 0; i < n; i++)
  {
    stringstream ss;
    string str;
    getline(cin, str);
    ss << str;
    int temp;
    int col = 0;
    while (ss >> temp)
    {
      cost[i][col] = temp;
      col++;
    }
  }
  // CALCULATION
  // initialize
  for (int j = 0; j < 4; j++)
  {
    DPTable[0][j] = cost[0][j];
  }
  // DP[i][j] means when i-th house painting j color, the minimum cost 
  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      int temp1 = min(DPTable[i-1][(j+1)%4], DPTable[i-1][(j+2)%4]);
      int temp2 = min(DPTable[i-1][(j+3)%4], temp1);
      DPTable[i][j] = temp2 + cost[i][j];
    }
  }
  int totalMinCost = INT_MAX;
  
  for (int j = 0; j < 4; j++)
  {
    totalMinCost = min(totalMinCost, DPTable[n-1][j]);
  }
  // OUTPUT
  cout << totalMinCost << endl;
  return 0;
}