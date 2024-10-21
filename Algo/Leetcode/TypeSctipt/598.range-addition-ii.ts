/*
 * @lc app=leetcode id=598 lang=typescript
 *
 * [598] Range Addition II
 */

// @lc code=start
function maxCount(m: number, n: number, ops: number[][]): number {
	if (ops.length === 0) return m * n;
	let minX = m;
	let minY = n;
	for (const op of ops) {
		minX = Math.min(minX, op[0]);
		minY = Math.min(minY, op[1]);
	}
	return minX * minY;
}
// @lc code=end
