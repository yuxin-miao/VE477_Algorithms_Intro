/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int num = (int)cost.size();
        vector<int> totalCost(num, 1000);
        totalCost[0] = cost[0];
        totalCost[1] = cost[1];
        for (int i = 2; i < num; i++)
        {
            totalCost[i] = min(totalCost[i - 1], totalCost[i - 2]) + cost[i];
        }
        return min(totalCost[num - 1], totalCost[num - 2]);
    }
};
/* int main() {
    int num;
    cin >> num;
    Solution sol;
    vector<int> cost(num, 0);
    for (int i = 0; i < num; i++)
    {
        int val;
        cin >> val;
        cost[i] = val;
    }
    
    cout << sol.minCostClimbingStairs(cost) << endl; 

} */
// @lc code=end

