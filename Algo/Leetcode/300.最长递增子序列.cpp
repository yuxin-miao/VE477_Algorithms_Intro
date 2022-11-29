/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> DPTable(nums.size(), 0);
        DPTable[0] = 1;
        int maxReturn = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            int temp = 1;
            for (int j = i - 1; j >= 0; j--)
            {
                if (nums[i] > nums[j])
                    temp = max(temp, DPTable[j] + 1);
            }
            //cout << i << " " << temp << endl;
            DPTable[i] = temp;
            maxReturn = max(maxReturn, temp);
        }
        return maxReturn;
    }
};
// @lc code=end

