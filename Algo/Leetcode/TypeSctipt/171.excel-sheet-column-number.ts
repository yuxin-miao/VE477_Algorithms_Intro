/*
 * @lc app=leetcode id=171 lang=typescript
 *
 * [171] Excel Sheet Column Number
 */

// @lc code=start
const convertChar = (char: string): number => {
	return char.charCodeAt(0) - 64;
};
function titleToNumber(columnTitle: string): number {
	if (columnTitle.length === 1) return convertChar(columnTitle);
	let result = 0;
	for (let char of columnTitle) {
		result = result * 26 + convertChar(char);
	}
	return result;
}
// @lc code=end
