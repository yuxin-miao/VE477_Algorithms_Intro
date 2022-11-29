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