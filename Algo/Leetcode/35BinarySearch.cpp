/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;
        if (target < nums[0]) return 0;
        if (target > nums[right]) return nums.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (target == nums[mid]) return mid;
            else if (target > nums[mid]) left = mid + 1;
            else if (target < nums[mid]) right = mid;
        }
        // cout << left << " " << right << endl;
        if (target > nums[left]) return left + 1;
        else return left;
    }
};
/* 
int main() {
    vector<int> nums = {1,3,5,6};
    Solution sol;
    cout << sol.searchInsert(nums, 4) << endl;
    return 0;
} */
// @lc code=end

