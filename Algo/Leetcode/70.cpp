/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return 1;
        vector<int> dpTable(n + 1, 0);
        dpTable[1] = 1;
        dpTable[2] = 2;
        for (int i = 3; i < n + 1; i++) {
            dpTable[i] = dpTable[i - 1] + dpTable[i - 2];
            
        }        
        return dpTable[n];
        //recursion sol
        //return climbStairsHelper(n);
        //DP is faster than recursion, as it remembers the value to save memory and time
    }
    int climbStairsHelper(int n) {
        
        if (n == 0) return 1;
        else if (n < 0) return 0;
        return climbStairsHelper(n - 1) + climbStairsHelper(n - 2);
    }
};
/* int main() {
    int num;
    cin >> num;
    Solution sol;

    cout << sol.climbStairs(num) << endl; 

} */
// @lc code=end

