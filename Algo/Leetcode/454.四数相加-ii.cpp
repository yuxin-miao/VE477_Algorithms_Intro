/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> sumNum12;
        for (auto &&i : nums1)
        {
            for (auto &&j : nums2)
            {
                sumNum12[i+j]++;
            }
        }
        int count = 0;
        for (auto &&i : nums3)
        {
            for (auto &&j : nums4)
            {
                count += sumNum12[-(i + j)];
            }
        }
        return count;
    }
};
// @lc code=end

