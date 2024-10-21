/*
 * @lc app=leetcode id=594 lang=typescript
 *
 * [594] Longest Harmonious Subsequence
 */

// @lc code=start
function findLHS(nums: number[]): number {
	let map: Record<number, number> = {};
	let result = 0;
	for (let num of nums) {
		if (map[num]) map[num]++;
		else map[num] = 1;
		if (map[num - 1]) result = Math.max(result, map[num] + map[num - 1]);
		if (map[num + 1]) result = Math.max(result, map[num] + map[num + 1]);
	}
	return result;
}
// @lc code=end
