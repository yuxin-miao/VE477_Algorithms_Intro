/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        int j = b.length() - 1;
        int i = a.length() - 1;
        int carry = 0;
        string res;
        while (i >= 0 || j >= 0)
        {
            carry += (i >= 0) ? a[i] - '0' : 0;
            carry += (j >= 0) ? b[j] - '0' : 0;
            res = ((carry % 2) ? '1' : '0') + res;
            j--;
            i--;
            carry /= 2;

        }
        if (carry % 2) res = '1' + res;

        return res;
    }
};
/* int main() {
    string inputStr0;
    string inputStr1;
    getline(cin, inputStr0);
    getline(cin, inputStr1);
    Solution sol;
    cout << sol.addBinary(inputStr0, inputStr1) << endl;
} */
// @lc code=end

