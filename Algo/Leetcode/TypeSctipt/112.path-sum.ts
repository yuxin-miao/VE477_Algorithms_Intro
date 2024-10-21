/*
 * @lc app=leetcode id=112 lang=typescript
 *
 * [112] Path Sum
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function hasPathSum(root: TreeNode | null, targetSum: number): boolean {
	const queue = [];
	if (root) {
		queue.push([root.left, root.val, root.right]);
	}

	while (queue.length > 0) {
		const [left, value, right] = queue.shift();
		if (left === null && right === null) {
			if (value !== targetSum) {
				continue;
			}

			return true;
		}

		if (left) {
			queue.push([left.left, value + left.val, left.right]);
		}
		if (right) {
			queue.push([right.left, value + right.val, right.right]);
		}
	}

	return false;
}
// @lc code=end
