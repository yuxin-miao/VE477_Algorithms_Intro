/*
 * @lc app=leetcode.cn id=1046 lang=cpp
 *
 * [1046] 最后一块石头的重量
 */

// @lc code=start
#include <vector>
#include <queue>
#include <numeric>
using namespace std;
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // 1' priority queue: because always need two stones with max weight
        priority_queue<int> stoneQueue(stones.begin(), stones.end());

        while (stoneQueue.size() > 1)
        {
            int s1 = stoneQueue.top();
            stoneQueue.pop();
            int s2 = stoneQueue.top();
            stoneQueue.pop();
            if (s1 != s2) {
                stoneQueue.push(s1 - s2);
            }
        }
        if (stoneQueue.empty()) return 0;
        return stoneQueue.top();
        

    }
};
// @lc code=end

