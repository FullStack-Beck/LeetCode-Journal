/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean isBalanced(TreeNode root) {
        return depth(root) != -1;
    }
    public int depth(TreeNode root) {
        
        if(root == null) {
            return 0;
        }

        int left_depth = depth(root.left);
        if(left_depth == -1) {return -1;}
        int right_depth = depth(root.right);
        if(right_depth == -1) {return -1;}

        if(Math.abs(left_depth - right_depth) > 1) {
            return -1;
        }

        return 1 + Math.max(left_depth, right_depth);
    }
}
