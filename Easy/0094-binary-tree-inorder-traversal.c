/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 // -> is required in C because node.val or node.left points to the whole struct in memory, rather then the pointer -> is the same as saying (*node).####
int countnodes(struct TreeNode* root) {
    if(root == NULL) return 0;
    return 1 + countnodes(root->left) + countnodes(root->right);
}

void traverse(struct TreeNode* node, int* result, int* index) {
    if (node == NULL) {
        return;
    }

    traverse(node->left, result, index);
    result[(*index)++] = node->val;
    traverse(node->right, result, index);

}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = countnodes(root);
    
    // this is allocating the memory
    int* result = (int*)malloc((*returnSize) * sizeof(int));
    // this makes sure the memory allocation doesnt allocate something when theres nothing
    if (result == NULL) {
        *returnSize = 0;
        return NULL; // Memory allocation failed
    }

    // remember index = 0 exists in memory somewhere
    int index = 0;
    traverse(root, result, &index); // & means address of, \this is required so when we do our recursion in traverse our nested traverse, we want to have the index increment up for our original traverse function not just the new nested traverse, if we dont, the nested traverse is a new copy and only increments for itself.

    return result; 
}
