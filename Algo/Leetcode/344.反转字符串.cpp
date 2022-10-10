/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        int lPtr = 0;
        int rPtr = s.size() - 1;
        while (lPtr < rPtr) {
            char temp = s[lPtr];
            s[lPtr] = s[rPtr];
            s[rPtr] = temp;
            lPtr++;
            rPtr--;
        }
    }
};
// @lc code=end

