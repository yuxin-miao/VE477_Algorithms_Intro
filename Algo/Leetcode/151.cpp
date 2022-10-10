/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        int ptr1 = 0;
        while (s[ptr1] == ' ') {
            ptr1++;
        }
        s = s.substr(ptr1, s.size());
        ptr1 = (int)s.length() - 1;
        int ptr2 = (int)s.length() - 1;
        string res;
        while (ptr1 > 0) {
            while (s[ptr2] == ' ' && ptr2 != 0)
            {
                ptr2--;
            }
            ptr1 = ptr2;
            while(s[ptr1] != ' ' && ptr1 != 0) {
                ptr1--;
            }
            if (ptr1 == 0) break;
            res += s.substr(ptr1 + 1, ptr2 - ptr1);
            ptr2 = ptr1;
            res += ' ';
        }
        res += s.substr(0, ptr2 - ptr1 + 1);
        ptr2 = res.size() - 1;
        while (res[ptr2] == ' ') {
            ptr2--;
        }


        return res.substr(ptr1, ptr2 + 1);
    }
};
/* int main() {
    string str;
    std::getline(std::cin, str);

    Solution sol;
    cout << sol.reverseWords(str) << "!" << endl;
} */
// @lc code=end

