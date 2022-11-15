/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> DPTable(amount + 1, 0);
        DPTable[0] = 1;
        for (int coin : coins) {
            for (int i = coin; i < amount + 1; i++)
            {
                DPTable[i] += DPTable[i-coin];
            }
            
        }
        return DPTable[amount];
    }
};
/* int main() {
    int amount;
    cin >> amount;
    int n;
    cin >> n;
    vector<int> coins;
    int c;
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        coins.push_back(c);
    }
    Solution sol;
    cout << sol.change(amount, coins) << endl;
    
} */
// @lc code=end

