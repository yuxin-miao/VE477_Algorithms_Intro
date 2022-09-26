/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int begin = 0;
        int end = nums.size() - 1;
        vector<vector<int>> res;

        while (begin < end) {
            int tofind =  0 - nums[begin] - nums[end];
            cout << tofind << endl;
            if (tofind < 0) {
                // nums[begin] < nums[end]
                if (nums[begin] > tofind) {
                    while (nums[end] + nums[begin] > -nums[begin] && (end > begin)) end--;
                    continue;
                }
                int currPtr = begin++;
                if (nums[currPtr] > tofind) continue;

                while (nums[currPtr] <= tofind && (end > currPtr)) {
                    if (nums[currPtr] == tofind) 
                        {res.push_back(vector<int>{nums[begin], nums[currPtr], nums[end]});cout << nums[currPtr] << " in 1" << endl;}
                    currPtr++;
                }
                end--;
            }
            else if (tofind >= 0) {
                if (nums[end] < tofind) {
                    while (-(nums[end] + nums[begin]) > -nums[end] && (end > begin)) begin++;
                    continue;
                }
                int currPtr = end--;
                if (nums[currPtr] < tofind) continue;
                while (nums[currPtr] >= tofind && (currPtr > begin)) {
                    if (nums[currPtr] == tofind) 
                        {res.push_back(vector<int>{nums[begin], nums[currPtr], nums[end]});cout << nums[currPtr] << " in 2" << endl;}
                    currPtr--;
                }
                begin++;
            }
        }
        return res;
    }
};
// @lc code=end

