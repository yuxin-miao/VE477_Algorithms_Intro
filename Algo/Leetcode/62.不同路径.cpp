/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dpTable(m , vector<int> (n, 0)); 
        for (int j = 0; j < n; j++)
        {
            dpTable[0][j] = 1;
        }
        for (int i = 0; i < m; i++)
        {
            dpTable[i][0] = 1;
        }
        
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dpTable[i][j] = dpTable[i][j-1] + dpTable[i-1][j];
            }
        }
        return dpTable[m-1][n-1];
    }
};
// @lc code=end

