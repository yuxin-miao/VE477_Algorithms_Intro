/*
 * @lc app=leetcode id=2996 lang=typescript
 *
 * [2996] Smallest Missing Integer Greater Than Sequential Prefix Sum
 */

// @lc code=start
function missingInteger(nums: number[]): number {
	let prefixSum = nums[0];
	for (let i = 1; i < nums.length; i++) {
		if (nums[i] === nums[i - 1] + 1) prefixSum += nums[i];
		else break;
	}
	let result = prefixSum;
	const set = new Set<number>(nums);
	while (set.has(result)) result += 1;
	return result;
}
// @lc code=end
