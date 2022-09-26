/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
// try to implement inplace solution
/*     vector<int> sortedSquares(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int lnum = nums[left] < 0 ? -nums[left] : nums[left];
            int rnum = nums[right] < 0 ? -nums[right] : nums[right];
            if (lnum < rnum) {
                nums[right] = rnum * rnum;
                right--;
            } else if (lnum > rnum) {
                nums[right] = lnum * lnum;
                nums[left] = rnum;
                right--;
            } else {
                nums[right] = rnum * rnum;
                nums[left] = nums[right - 1];
                nums[right - 1] = rnum * rnum;
                right-=2;
            }
        }
        return nums;
    } */
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        vector<int> ans(nums.size(), 0);
        int pos = right;
        while (left <= right) {
            if (nums[left] * nums[left] > nums[right] * nums[right]) {
                ans[pos] = nums[left] * nums[left];
                left++;
            } else {
                ans[pos] = nums[right] * nums[right];
                right--;
            }
            pos--;
        }
        return ans;
    }
};
/* void printVector(vector<int>& nums) {
    for (auto &&i : nums)
    {
        cout << i << " ";
    }
    
}
int main() {
    vector<int> nums = {-5,-3,-2,-1,2,3,11};
    Solution solution;
    vector<int> res = solution.sortedSquares(nums);
    printVector(res);
} */
// @lc code=end

