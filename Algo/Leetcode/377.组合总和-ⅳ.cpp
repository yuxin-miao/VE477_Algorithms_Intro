/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> DPTable(target + 1, 0);
        DPTable[0] = 1;
        for (int i = 1; i < target + 1; i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if (i >= nums[j] && DPTable[i] < INT_MAX - DPTable[i - nums[j]]) DPTable[i] += DPTable[i-nums[j]];
            }
            
        }
        return DPTable[target];
    }
};
// @lc code=end

