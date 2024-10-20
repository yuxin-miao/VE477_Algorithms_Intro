/*
 * @lc app=leetcode id=13 lang=typescript
 *
 * [13] Roman to Integer
 */

// @lc code=start
function romanToInt(s: string): number {
	const mapping: Record<string, number> = {
		I: 1,
		V: 5,
		X: 10,
		L: 50,
		C: 100,
		D: 500,
		M: 1000,
	};
	const chars: string[] = s.split("");
	let result: number = 0;
	let prevInt: number = 1000;
	for (const char of chars) {
		const tempInt = mapping[char];
		if (prevInt < tempInt) {
			result = result - prevInt + tempInt - prevInt;
		} else {
			result += tempInt;
		}
		prevInt = tempInt;
	}
	return result;
} // @lc code=end
