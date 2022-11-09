/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */

// @lc code=start
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        // 2' DP: similar to find two subsets that has same weight ? really???  
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int halfSum = sum / 2;
        vector<int> DPTable(halfSum + 1, 0);
        for (int i = 0; i < stones.size(); i++)
        {
            for (int j = halfSum; j >= stones[i]; j--)
            {
                DPTable[j] = max(DPTable[j], DPTable[j - stones[i]] + stones[i]);
            }
        }
        return sum - DPTable[halfSum] - DPTable[halfSum];
    }
};
// @lc code=end

