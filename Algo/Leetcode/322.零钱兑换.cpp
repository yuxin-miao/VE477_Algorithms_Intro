/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> DP(amount + 1, INT_MAX);
        DP[0] = 0;
        for (int i = 1; i < amount + 1; i++)
        {
            for (int j = 0; j < coins.size(); j++)
            {
                if (i >= coins[j] && DP[i-coins[j]] < INT_MAX) {
                    DP[i] = min(DP[i - coins[j]] + 1, DP[i]);
                }
            }
            
        }
        return DP[amount] == INT_MAX ? -1 : DP[amount];
    }
};
// @lc code=end

