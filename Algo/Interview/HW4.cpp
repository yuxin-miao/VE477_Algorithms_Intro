#include <iostream>
#include <string>
using namespace std;


int main() {
  string user1;
  cin >> user1;
  int users;
  cin >> users;
  //int carry = 0;
  int binaryBase = 1;
  int numUser1 = 0;
  for (int i = user1.size() - 1; i >= 0; i--)
  {
    int temp = (user1[i] - '0') * binaryBase;
    numUser1 += temp;
    binaryBase *= 2;

  }
  int total = 0;
  for (int i = 1; i < users + 1; i++)
  {
    if ((numUser1&i) != 0) total++;
  }
  
  cout << total << endl;
  return 0;
}