/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int integerBreak(int n) {
        if (n <= 2) return 1;
        vector<int> integerDP(n + 1, 0);
        integerDP[1] = 1;
        integerDP[2] = 2;
        for (int i = 3; i < n + 1; i++)
        {
            int sum = 0;
            for (int j = 1; j < i / 2 + 1; j++)
            {
                sum = max(integerDP[j] * integerDP[i-j], sum);              
            }
            integerDP[i] = i == n ? sum : max(sum, i);
        }
        return integerDP[n];
    }
};
/* int main() {
    int num;
    cin >> num;
    Solution sol;
    cout << sol.integerBreak(num) << endl;
} */
// @lc code=end

