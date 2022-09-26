/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (target < nums[mid]) {
                right = mid;
            } else if (target > nums[mid]) {
                left = mid + 1;
            } else {
                return mid;
            }
        }
        if (nums[left] == target) return left;
        else return -1;
    }
};
/* int main() {
    vector<int> nums = {1,2,3,4,5};
    Solution solution;
    cout << solution.search(nums, 5) << endl;
} */
// @lc code=end

