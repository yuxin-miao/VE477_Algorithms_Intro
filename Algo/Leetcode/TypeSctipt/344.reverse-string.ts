/*
 * @lc app=leetcode id=344 lang=typescript
 *
 * [344] Reverse String
 */

// @lc code=start
/**
 Do not return anything, modify s in-place instead.
 */
function reverseString(s: string[]): void {
	let leftPtr = 0;
	let rightPtr = s.length - 1;
	while (leftPtr < rightPtr) {
		let tempChar = s[leftPtr];
		s[leftPtr] = s[rightPtr];
		s[rightPtr] = tempChar;
		leftPtr++;
		rightPtr--;
	}
}
// @lc code=end
