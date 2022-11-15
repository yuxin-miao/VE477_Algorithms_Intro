/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int numSquares(int n) {
        vector<int> DP(n + 1, INT_MAX);
        DP[0] = 0;
        for (int i = 1; i < n+1; i++)
        {
            for (int j = 1; j <= sqrt(n); j++)
            {
                if (i >= j*j && DP[i - j*j] != INT_MAX) 
                    DP[i] = min(DP[i - j*j] + 1, DP[i]);
            }
            
        }
        return DP[n];
        
    }
};
// @lc code=end

