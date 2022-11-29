#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

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