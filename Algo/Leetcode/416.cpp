/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
#include <vector>
#include <iostream>
#include <numeric>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        int halfSum = sum / 2;
        vector<int> DP1D(halfSum + 1, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = halfSum; j >= nums[i]; j--)
            {
                DP1D[j] = max(DP1D[j], DP1D[j - nums[i]] + nums[i]);
            }
        }
        if (DP1D[halfSum] == halfSum) return true;
        return false;
/*         vector<vector<int>> DPTable(nums.size(), vector<int>(halfSum + 1, 0));
        for (int i = 0; i < nums.size(); i++)
        {
            DPTable[i][0] = 0;
        }
        for (int j = 0; j < halfSum + 1; j++)
        {
            DPTable[0][j] = nums[0] > j ? 0 : nums[0];
        }
        
        
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 1; j < halfSum + 1; j++)
            {
                if (nums[i] < j)
                {
                    DPTable[i][j] = max(DPTable[i-1][j], DPTable[i][j - nums[i]] + nums[i]);
                } else {
                    DPTable[i][j] = DPTable[i-1][j];
                }
                if (DPTable[i][j] == halfSum) return true;
            }
        } 
        return false;
        */

        
    }
};
/* int main() {
    int num;
    vector<int> nums;
    while (cin >> num)
    {
        nums.push_back(num);
    }
    Solution sol;
    cout << sol.canPartition(nums) << endl;
    
} */
// @lc code=end

