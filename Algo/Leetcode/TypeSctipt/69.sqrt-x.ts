/*
 * @lc app=leetcode id=69 lang=typescript
 *
 * [69] Sqrt(x)
 */

// @lc code=start
function mySqrt(x: number): number {
	let num: number = 0;
	if (x === 0) return 0;
	while (num <= x) {
		if (num * num === x) return num;
		if (num * num > x) break;
		num++;
	}
	return num - 1;
	return num - 1;
}
// @lc code=end
