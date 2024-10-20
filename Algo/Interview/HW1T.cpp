#include <iostream>
#include <string>
using namespace std;
/**
 * @brief 11.23 HW机考第一题 100pt
 * 一共32个地点，第一个输入表示一个用户访问过的地点用1表示，没表示过的用0表示
 * 第二个输入为十进制数字，每一个小于该数字的表示去过的，如果有都为1的位则都去过。输出总共都去过的地方
 * 比如输入'10111','6' 
 * 则有'6'代表的：1，10，11，100，101，110和'10001'分别比较 
 * 1：有相同
 * 10：没有相同
 * 11：有相同
 * 100:没有相同
 * 101：有
 * 110：没有
 * 输出为3
 * @return int 
 */

int main() {
  string user1;
  cin >> user1;
  int users;
  cin >> users;
  //int carry = 0;
  int binaryBase = 1;
  int total = 0;
  for (int i = 0; i < user1.size(); i++)
  {
    if (user1[i] == '1') {
      if (users >= binaryBase * 2) total += binaryBase;
      else if (users > binaryBase && users < binaryBase * 2) {
        total += (binaryBase * 2 - users);
      }
    }
        cout << i << " " << binaryBase << " "  << total << endl;

    binaryBase *= 2;

  }

  cout << total << endl;
  return 0;
}