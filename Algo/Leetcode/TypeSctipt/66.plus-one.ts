/*
 * @lc app=leetcode id=66 lang=typescript
 *
 * [66] Plus One
 */

// @lc code=start
function plusOne(digits: number[]): number[] {
	let leadingOne = 1;
	for (let i = digits.length - 1; i >= 0; i--) {
		if (digits[i] === 9) digits[i] = 0;
		else {
			digits[i] += 1;
			leadingOne = 0;
			break;
		}
	}
	if (leadingOne) digits.unshift(1);
	return digits;
}
// @lc code=end
