/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> binaryRange(vector<int>& nums, int target, int left, int right) { 
        if (nums[left] < target)
        if (nums[left] == target && nums[right] == target)
        {
            return vector<int>{left, right};
        }
        
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1, -1};
        
        int left = 0;
        int right = nums.size() - 1;
        if (target < nums[left]) return res;
        if (target > nums[right]) return res;
        while (left < right) {
            int mid = (left + right) / 2;
            if (target == nums[mid]) {

            }
        }
    }
};
// @lc code=end

