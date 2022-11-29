/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> DPTable(nums1.size(), vector<int>(nums2.size(), 0));
        int maxReturn = 0;
        for (int i = 0; i < nums1.size(); i++)
        {
            DPTable[i][0] = nums1[i] == nums2[0] ? 1 : 0;
            maxReturn = max(maxReturn, DPTable[i][0]);

        }
        for (int i = 0; i < nums2.size(); i++)
        {
            DPTable[0][i] = nums1[0] == nums2[i] ? 1 : 0;
            maxReturn = max(maxReturn, DPTable[0][i]);

        }
        for (int i = 1; i < nums1.size(); i++)
        {
            for (int j = 1; j < nums2.size(); j++)
            {
                if (nums1[i] == nums2[j])
                {
                    DPTable[i][j] = DPTable[i-1][j-1] + 1;
                }
                maxReturn = max(maxReturn, DPTable[i][j]);
                //if (maxReturn == 1) cout << i << ' ' << j << endl;
            }
            
        }
        return maxReturn;
        
        
    }
};
/* int main() {
    vector<int> nums1 = {70,39,25,40,7};
    vector<int> nums2 = {52,20,67,5,31};
    Solution solution;
    cout << solution.findLength(nums1, nums2);
}
 */
// @lc code=end

