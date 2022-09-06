/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
using namespace std;
#include <vector> 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 220806
        int minPrice = prices[0];
        int maxProfit = 0;
        for (auto i : prices) {
            if (i < minPrice) 
                minPrice = i;
            if ((i - minPrice) > maxProfit) 
                maxProfit = i - minPrice;
        }
        return maxProfit;
    }
};
// @lc code=end

