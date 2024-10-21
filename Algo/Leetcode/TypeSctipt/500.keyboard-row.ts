/*
 * @lc app=leetcode id=500 lang=typescript
 *
 * [500] Keyboard Row
 */

// @lc code=start
function findWords(words: string[]): string[] {
	let result: string[] = [];

	for (let word of words) {
		let chars = [...new Set(word.toLowerCase())];

		let row1 = chars.map((char) => "qwertyuiop".includes(char)).every((e) => e);
		let row2 = chars.map((e) => "asdfghjkl".includes(e)).every((e) => e);
		let row3 = chars.map((e) => "zxcvbnm".includes(e)).every((e) => e);
		if (row1 || row2 || row3) result.push(word);
	}
	return result;
}
// @lc code=end
