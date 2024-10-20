/*
 * @lc app=leetcode id=20 lang=typescript
 *
 * [20] Valid Parentheses
 */

// @lc code=start
function isValid(s: string): boolean {
	if (s.length === 1) return false;
	const chars = s.split("");
	let bracketsStack: string[] = [];
	for (let char of chars) {
		if (char === "{" || char === "(" || char === "[") bracketsStack.push(char);
		else {
			if (char === "}" && bracketsStack.pop() !== "{") return false;
			else if (char === ")" && bracketsStack.pop() !== "(") return false;
			else if (char === "]" && bracketsStack.pop() !== "[") return false;
		}
	}
	if (bracketsStack.length !== 0) return false;
	return true;
}
// @lc code=en
// const stack: string[] = [];
// const bracketMap = {
// 	")": "(",
// 	"}": "{",
// 	"]": "[",
// };

// for (let char of s) {
// 	if (char === "(" || char === "{" || char === "[") {
// 		stack.push(char);
// 	} else {
// 		if (stack.length === 0 || stack.pop() !== bracketMap[char]) {
// 			return false;
// 		}
// 	}
// }

// return stack.length === 0;
