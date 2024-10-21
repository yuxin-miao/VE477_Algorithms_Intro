/*
 * @lc app=leetcode id=28 lang=typescript
 *
 * [28] Find the Index of the First Occurrence in a String
 */

// @lc code=start
function strStr(haystack: string, needle: string): number {
	let str1 = haystack.split("");
	let str2 = needle.split("");
	for (let i = 0; i < str1.length; i++) {
		if (str1.length - i < str2.length) return -1;
		let tempIndex = i;
		for (let j = 0; j < str2.length; j++) {
			if (str1[tempIndex] !== str2[j]) break;
			else tempIndex++;
		}
		if (tempIndex - i === str2.length) return i;
	}
	return -1;
}
// @lc code=end
