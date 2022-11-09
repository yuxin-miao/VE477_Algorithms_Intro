/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 3) return nums.size();
        int moveForward = 0;
        int numCount = 1;

        int prev = nums[0];
       for (int i = 1; i < nums.size(); i++)
       {
            if (nums[i] == prev) {
                numCount++;
            } else {
                prev = nums[i];
                numCount = 1;
            }
            if (numCount > 2) {
                moveForward++;
            } else {
                nums[i-moveForward] = nums[i];
            }

       }

        return nums.size() - moveForward;
    }
};
/* template <class T>
void printVector(vector<T>& v) {
    for (auto &i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}
int main() {
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
    cout << sol.removeDuplicates(nums) << endl;
    printVector(nums);
    
} */
// @lc code=end

