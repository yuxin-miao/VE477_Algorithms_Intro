/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include <string>
#include <unordered_set>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        unordered_set<char> recordChar;
        int maxLength = 1;
        int j = 1;
        for (int i = 0; i < s.length() - 1; i++)
        {   
            recordChar.clear();
            recordChar.emplace(s[i]);
            j = i + 1;
            while (j != s.length() && recordChar.find(s[j]) == recordChar.end())  {
                recordChar.emplace(s[j]);
                j++;
            }
            maxLength = max(maxLength, j-i);
        }
        return maxLength;
    }
};
/* int main () {
    string str;
    getline(cin, str);
    Solution sol;
    cout << sol.lengthOfLongestSubstring(str) << endl;
} */
// @lc code=end

