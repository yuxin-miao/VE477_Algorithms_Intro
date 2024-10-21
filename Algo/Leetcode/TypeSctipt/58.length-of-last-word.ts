/*
 * @lc app=leetcode id=58 lang=typescript
 *
 * [58] Length of Last Word
 */

// @lc code=start
function lengthOfLastWord(s: string): number {
	let str = s.trim().split(" ");
	return str[str.length - 1].length;
}
// @lc code=end
