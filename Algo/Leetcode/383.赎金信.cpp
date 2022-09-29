/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // first method 
/*         unordered_map<char, int> charCount;
        for (auto &&i : magazine)
        {
            charCount[i]++;
        }
        for (auto &&i : ransomNote)
        {
            charCount[i]--;
            if (charCount[i] < 0) return false;
        }
        return true; */

        // second method
        int record[26] = {0};
        if (ransomNote.size() > magazine.size()) {
            return false;
        }
        for (int i = 0; i < magazine.length(); i++) {
           record[magazine[i]-'a'] ++;
        }
        for (int j = 0; j < ransomNote.length(); j++) {
            record[ransomNote[j]-'a']--;
            if(record[ransomNote[j]-'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

