/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // another solution for recording the number of each character
/*         int record[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            // 并不需要记住字符a的ASCII，只要求出一个相对数值就可以了
            record[s[i] - 'a']++;
        } */
        if (s.length() != t.length())
        {
            return false;
        }
        
        map<char, int> anagram;
        for (auto &i : s)
        {
            anagram[i]++;
        }
        for (auto &i : t)
        {
            anagram[i]--;
            if (anagram[i] == 0) anagram.erase(i);
        }
        if (anagram.empty())
        {
            return true;
        }
        return false;
        
        
    }
};
// @lc code=end

