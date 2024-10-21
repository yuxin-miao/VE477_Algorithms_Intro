/*
 * @lc app=leetcode id=88 lang=typescript
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
/**
 Do not return anything, modify nums1 in-place instead.
 */
function merge(nums1: number[], m: number, nums2: number[], n: number): void {
	let index = m;

	nums2.forEach((val) => {
		nums1[index] = val;
		index++;
	});
	nums1.sort((a, b) => a - b);
}
// @lc code=end
