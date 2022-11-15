/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector<int> DP(nums.size(), 0);
        DP[0] = nums[0];
        DP[1] = max(nums[0], nums[1]);

        for (int j = 2; j < nums.size(); j++)
        {
            DP[j] = max(DP[j-1], DP[j-2] + nums[j]);
        }
            
        return DP[nums.size() - 1];
        
    }
};
// @lc code=end

