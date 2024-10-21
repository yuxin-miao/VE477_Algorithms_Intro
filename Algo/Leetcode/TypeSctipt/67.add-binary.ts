/*
 * @lc app=leetcode id=67 lang=typescript
 *
 * [67] Add Binary
 */

// @lc code=start
function addBinary(a: string, b: string): string {
	let result: string = "";
	let carry = 0;
	for (let i = a.length - 1, j = b.length - 1; i >= 0 || j >= 0; i--, j--) {
		const num1 = parseInt(a[i] ?? "0");
		const num2 = parseInt(b[j] ?? "0");
		const sum = num1 + num2 + carry;
		carry = sum > 1 ? 1 : 0;
		result = (sum % 2) + result;
	}
	return carry ? "1" + result : result;
}
// @lc code=end
