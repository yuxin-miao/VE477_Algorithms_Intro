/*
 * @lc app=leetcode.cn id=859 lang=cpp
 *
 * [859] 亲密字符串
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.length() != goal.length() || s.length() == 1) return false;
        int idx0 = 0;
        int idx1 = 0;
        bool duplicateFlag = false;

        for (int i = 0; i < s.length(); i++)
        {
            if (!duplicateFlag) {
                size_t pos = s.find_first_of(s[i]);
                if ((int)pos < i) duplicateFlag = true;
            }
            if (s[i] != goal[i]) {
                if (idx0 == 0) idx0 = i;
                else if (idx1 == 0) idx1 = i;
                else return false;
            }

           
        }
        if (idx0 == idx1) {
            if (duplicateFlag) return true;
            return false;
        }
        if (s[idx0] == goal[idx1] && s[idx1] == goal[idx0]) return true;
        return false;
        
    }
};
// @lc code=end

