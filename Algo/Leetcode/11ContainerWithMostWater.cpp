/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        // double pointers 
        int ptr0 = 0;
        int ptr1 = height.size() - 1;
        int maxArea = 0;
        while (ptr0 < ptr1) {

            int currArea = min(height[ptr0], height[ptr1]) * (ptr1 - ptr0);
            // cout << ptr0 << ' '  << height[ptr0] << ' ' << ptr1 << ' ' << height[ptr1] << ' ' <<  currArea << endl;
            if (currArea > maxArea) {
                maxArea = currArea;
            }
            int minHeight = min(height[ptr0], height[ptr1]);
            if (height[ptr0] < height[ptr1]) {
                while (height[ptr0] <= minHeight && ptr0 < ptr1) ptr0++;
            } else {
                while (height[ptr1] <= minHeight && ptr0 < ptr1)
                {
                    ptr1--;
                }  
            }

            // one method to select which pointer needs to move 
/*             if (height[ptr0] < height[ptr1]) ptr0++;
            else if (height[ptr0] > height[ptr1]) ptr1--;
            else {
                ptr0++;
                ptr1--;
            } */
                 
        }
        return maxArea;
    }
};

int greedySol(vector<int>& height) {
    int maxArea = 0;
    for (int i = 0; i < height.size(); i++)
    {
        for (int j = i + 1; j < height.size(); j++)
        {
            int currArea = min(height[i], height[j]) * (j - i);
            if (currArea > maxArea) {
                maxArea = currArea;

            }
        }
        
    }
    return maxArea;
}

/* int main() {
    vector<int> height = {1, 2, 4, 3};
    Solution sol;
    cout << sol.maxArea(height) << endl;
    return 0;
} */
// @lc code=end

