/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
#include <unordered_set>
#include <iostream>
using namespace std;
class Solution {
public:
    bool isHappy(int n) {
        int num = n; 
        int sum = 0;
        unordered_set<int> sumResult;
        while (sumResult.find(sum) == sumResult.end()) {
            sumResult.insert(sum);
            sum = 0;
            while (true) {
                int digit = num % 10;
                sum = sum + digit * digit;
                if (num < 10) break;
                num /= 10;
            }
            if (sum == 1) return true;
            num = sum;

        }
        return false;
    }
};

/* int main() {
    int num;
    cin >> num;
    Solution sol;
    cout << sol.isHappy(num) << endl;

} */
// @lc code=end

