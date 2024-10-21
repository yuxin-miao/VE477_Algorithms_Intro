/*
 * @lc app=leetcode id=27 lang=typescript
 *
 * [27] Remove Element
 */

// @lc code=start
function removeElement(nums: number[], val: number): number {
	let leftPtr = 0;
	let rightPtr = nums.length - 1;
	while (leftPtr < rightPtr) {
		if (nums[leftPtr] === val) {
			nums[leftPtr] = nums[rightPtr];
			rightPtr--;
		} else leftPtr++;
	}
	if (nums[leftPtr] !== val) return leftPtr + 1;
	else return leftPtr;
}
// @lc code=end
