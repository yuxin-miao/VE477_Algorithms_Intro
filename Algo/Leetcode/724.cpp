/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心下标
 */

// @lc code=start
#include <vector>
#include <iostream>
#include <numeric>
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sumLeft = 0;
        int sumRight = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < nums.size(); i++)
        {
            
            sumRight -= nums[i];
            if (sumLeft == sumRight) return i;
            sumLeft += nums[i];
        }
        return -1;
    }
};
/* int main() {
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        nums.push_back(num);


    }
    Solution sol;
    cout << sol.pivotIndex(nums) << endl;
    
} */
// @lc code=end

