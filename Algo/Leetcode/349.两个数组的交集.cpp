/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> storeNum;
        vector<int> res;
        for (auto &&i : nums1)
        {
            storeNum.insert(i);
        }
        for (auto &&i : nums2)
        {
            auto iter = storeNum.find(i);
            if (iter != storeNum.end()) {
                res.push_back(i);
            }
            storeNum.erase(i);
        }
        return res;
        
    }
};
// @lc code=end

