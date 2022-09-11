/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (target == nums[mid]) return mid;
            else if (target < nums[mid]) right = mid;
            else left = mid + 1;
        }
        if (nums[left] == target) return left;
        return -1;
    }
};
// @lc code=end

