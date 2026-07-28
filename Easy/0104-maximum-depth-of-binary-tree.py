# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:

        if not root: # check the input to see if its null,
            return 0 

        left_depth = self.maxDepth(root.left) # because we call maxDepth we run this whole process again, if the root.left then is null its left_depth returns 0 in the new function it moves on
        right_depth = self.maxDepth(root.right) # if thats null it returns 0, it moves on

        return 1 + max(left_depth, right_depth) # so for our new nested function it returns 1 + compare 0 + 0 so then our original function can finally set left_depth to 1 and leave

