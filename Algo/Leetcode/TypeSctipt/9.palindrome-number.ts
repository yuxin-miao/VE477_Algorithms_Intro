/*
 * @lc app=leetcode id=9 lang=typescript
 *
 * [9] Palindrome Number
 */

// @lc code=start
function isPalindrome(x: number): boolean {
	const str = x.toString();
	const chars: string[] = str.split("");
	const length = str.length;
	let rightPtr = length - 1;
	for (let leftPtr = 0; leftPtr < length / 2; leftPtr++) {
		if (chars[leftPtr] != chars[rightPtr]) return false;
		rightPtr -= 1;
	}
	return true;
}
// @lc code=end
