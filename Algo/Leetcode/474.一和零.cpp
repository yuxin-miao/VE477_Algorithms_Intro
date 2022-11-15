/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> subsetNum(m+1, vector<int>(n+1, 0));
        for (string str : strs)
        {
            int num0 = count(str.begin(), str.end(), '0');
            int num1 = count(str.begin(), str.end(), '1');
            for (int i = m; i >= num0; i--)
            {
                for (int j = n; j >= num1; j--)
                {
                    subsetNum[i][j] = max(subsetNum[i][j], subsetNum[i-num0][j-num1] + 1);
                }
                
            }
        }
        
        return subsetNum[m][n];


        
    }
};
// @lc code=end

