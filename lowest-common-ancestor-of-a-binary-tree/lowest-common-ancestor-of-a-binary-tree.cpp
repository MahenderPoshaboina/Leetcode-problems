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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* x, TreeNode* y) {
        if (root == NULL) return nullptr;
    if (root->val == x->val || root->val == y->val) return root;

    TreeNode* left = lowestCommonAncestor(root->left, x, y);
    TreeNode* right = lowestCommonAncestor(root->right, x, y);

    if (left != nullptr && right != nullptr) return root;
    if (left != nullptr) return left;
    if (right != nullptr) return right;

    return nullptr;
    }
};