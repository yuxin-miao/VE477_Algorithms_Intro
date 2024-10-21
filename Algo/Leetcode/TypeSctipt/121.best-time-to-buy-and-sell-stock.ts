/*
 * @lc app=leetcode id=121 lang=typescript
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
function maxProfit(prices: number[]): number {
	let result = 0;
	let lowestPrice = prices[0];
	for (let i = 1; i < prices.length; i++) {
		if (prices[i] - lowestPrice > result) result = prices[i] - lowestPrice;
		else if (prices[i] < lowestPrice) lowestPrice = prices[i];
	}
	return result;
}
// @lc code=end
