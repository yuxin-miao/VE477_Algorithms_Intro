/*
 * @lc app=leetcode id=14 lang=typescript
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
function longestCommonPrefix(strs: string[]): string {
	const sortedStrs = strs.sort((a, b) => (a < b ? -1 : 1));
	let firstStr = sortedStrs[0];
	let lastStr = sortedStrs[sortedStrs.length - 1];
	let commonPrefix = [];
	for (let i = 0; i < firstStr.length; i++) {
		if (firstStr[i] === lastStr[i]) commonPrefix.push(firstStr[i]);
		else break;
	}
	return commonPrefix.join("");
}
// @lc code=end
