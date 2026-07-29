/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} targetSum
 * @return {boolean}
 */
var hasPathSum = function(root, targetSum) {

    if (root === null) {
        return false;
    }

    if(root.left === null && root.right === null) {
        return root.val === targetSum 
    }

    const remainingSum = targetSum - root.val; // 1st pass 22 - 5, inside node1.left pass 17 - 4, inside node2.left 13 - 11, inside node3.left 2 != 7 it returns false -5 != 7, inside node3.right 2 === 2 returns true
    return hasPathSum(root.left, remainingSum) || hasPathSum(root.right, remainingSum); // recursion, root.left root.left root.left returns false root.right returns true
};
