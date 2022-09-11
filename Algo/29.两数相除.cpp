/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        int count = 0;
        while (dividend > divisor) {
            dividend -= divisor;
            count += 1;
        }
        return count;
    }
};
// @lc code=end

