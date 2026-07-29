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

function minDepth(root: TreeNode | null): number {
    // 1. Base case
    if (root === null) return 0;

    // 2. If no left child, we MUST explore right
    if (root.left === null) return 1 + minDepth(root.right);

    // 3. If no right child, we MUST explore left
    if (root.right === null) return 1 + minDepth(root.left);

    // 4. Both children exist -> pick the shorter branch
    return 1 + Math.min(minDepth(root.left), minDepth(root.right));
};
