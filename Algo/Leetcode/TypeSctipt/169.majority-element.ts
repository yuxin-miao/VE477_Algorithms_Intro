/*
 * @lc app=leetcode id=169 lang=typescript
 *
 * [169] Majority Element
 */

// @lc code=start
function majorityElement(nums: number[]): number {
	let map: Record<number, number> = {};
	const majorityCount = nums.length / 2;
	for (let num of nums) {
		map[num] = (map[num] || 0) + 1;
		if (map[num] > majorityCount) return num;
	}
	return 0;
}
// @lc code=end
