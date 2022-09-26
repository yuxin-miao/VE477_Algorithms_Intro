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

