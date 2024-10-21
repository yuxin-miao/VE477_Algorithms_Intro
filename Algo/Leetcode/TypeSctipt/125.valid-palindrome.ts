/*
 * @lc app=leetcode id=125 lang=typescript
 *
 * [125] Valid Palindrome
 */

// @lc code=start
function isPalindrome(s: string): boolean {
	const str = s.toLowerCase().replace(/[^a-z0-9]/g, "");
	let start = 0;
	let end = str.length - 1;
	while (start < end) {
		if (str[start] !== str[end]) return false;
		start++;
		end--;
	}
	return true;
}
// @lc code=end
