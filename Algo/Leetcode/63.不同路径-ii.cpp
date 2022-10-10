/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1) return 0;
        vector<vector<int>> dpTable(m , vector<int> (n, 0)); 
        dpTable[0][0] = 1;
        for (int j = 1; j < n; j++)
        {

            dpTable[0][j] = obstacleGrid[0][j] == 0 ? dpTable[0][j - 1] : 0;
        }
        for (int i = 1; i < m; i++)
        {
            dpTable[i][0] = obstacleGrid[i][0] == 0 ? dpTable[i - 1][0] : 0;
        }
        
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {

                dpTable[i][j] = obstacleGrid[i][j] == 0 ? (dpTable[i][j-1] + dpTable[i-1][j]) : 0;
            }
        }
        return dpTable[m-1][n-1];
    }
};
// @lc code=end

