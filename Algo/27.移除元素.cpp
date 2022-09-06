/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
#include <vector>

using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int lPtr = 0;
        int rPtr = nums.size() - 1;
        while (lPtr <= rPtr) {
            if (nums[lPtr] == val) {
                nums[lPtr] = nums[rPtr];
                rPtr--;
            } else {
                lPtr++;
            }
        }
        return rPtr + 1;
        
    }
};
// @lc code=end

