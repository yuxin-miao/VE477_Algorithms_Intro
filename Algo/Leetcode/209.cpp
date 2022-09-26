/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
// O(n^2) brute force
/*     int minSubArrayLen(int target, vector<int>& nums) {
        int slowPtr = 0;
        int fastPtr = 0;
        int res = nums.size() + 1;
        while (fastPtr < nums.size())
        {
            // int newPtr = slowPtr + 1;
            int currRes = 0;
            int sum = 0;
            while (sum < target && currRes < res ) {
                if (fastPtr == nums.size()) return res > nums.size() ? 0 : res;

                sum += nums[fastPtr];
                // if (newPtr == slowPtr + 1 && nums[fastPtr] > nums[slowPtr]) newPtr = fastPtr;
                fastPtr++;
                currRes++;
            }
            res = currRes;
            slowPtr++;
            fastPtr = slowPtr;
        }
        return res >=nums.size() ? 0 : res;

    } */
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = nums.size() + 1;
        int sum = 0; 
        int i = 0; 
        int subLength = 0; 
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            
            while (sum >= target) {
                subLength = (j - i + 1);
                result = result < subLength ? result : subLength;
                sum -= nums[i++]; 
            }
        }

        return result == nums.size() + 1 ? 0 : result;
    }

};
/* void printVector(vector<int>& nums) {
    for (auto &&i : nums)
    {
        cout << i << " ";
    }
    
}
int main() {
    vector<int> nums = {10,5,13,4,8,4,5,11,14,9,16,10,20,8};
    Solution solution;
    cout << solution.minSubArrayLen(80, nums);
} */
// @lc code=end

