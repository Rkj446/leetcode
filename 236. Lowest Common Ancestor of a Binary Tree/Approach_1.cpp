/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
              if(!root|| root ==p|| root== q) return root;

        // Step 1: Ask left and right subtrees to search
         TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // Step 2 (Scenario 1): If both sides found something, we are the LCA!
    if (left && right) {
        return root;
    }
    // Step 3 (Scenario 2 & 3): Otherwise, pass whichever side found something up (or null)
    return left ? left : right;
    }

};