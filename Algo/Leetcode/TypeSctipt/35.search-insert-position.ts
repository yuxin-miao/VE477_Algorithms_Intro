/*
 * @lc app=leetcode id=35 lang=typescript
 *
 * [35] Search Insert Position
 */

// @lc code=start
function searchInsert(nums: number[], target: number): number {
	let result = 0;
	for (let i = 0; i < nums.length; i++) {
		if (nums[i] >= target) {
			return i;
		} else result = i;
	}
	if (nums[nums.length - 1] < target) result++;
	return result;
}
// @lc code=end
