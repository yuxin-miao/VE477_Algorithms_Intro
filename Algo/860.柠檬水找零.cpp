/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cashFive = 0;
        int cashTen = 0;
        for (int i = 0; i < bills.size(); i++)
        {           
            switch (bills[i])
            {
            case 5:
                cashFive++;
                break;
            case 10:
                cashFive--;
                cashTen++;
                break;
            case 20:
                if (cashTen != 0) {
                    cashTen--;
                    cashFive--;
                } else {
                    cashFive -= 3;
                }
                break;
            default:
                break;
            }
            if (cashFive < 0) return false;
        }
        return true;
    }
};
// @lc code=end

