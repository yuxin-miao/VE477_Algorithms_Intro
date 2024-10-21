/*
 * @lc app=leetcode id=541 lang=typescript
 *
 * [541] Reverse String II
 */

// @lc code=start
function reverseStr(s: string, k: number): string {
	if (s.length <= k) return s.split("").reverse().join("");
	let result = "";
	for (let i = 0; i < s.length; i += 2 * k) {
		let windowWidth = Math.min(i + 2 * k, s.length);
		let firstKReversed = s
			.slice(i, i + k)
			.split("")
			.reverse()
			.join("");
		let remainingPart = s.slice(i + k, windowWidth);
		result += firstKReversed + remainingPart;
	}
	return result;
}
// @lc code=end
