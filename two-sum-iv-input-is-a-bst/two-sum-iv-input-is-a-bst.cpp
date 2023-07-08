/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        set<int> s;
        return findSumPair(root, k, s);
    }
    
    bool findSumPair(TreeNode* root, int k, set<int>& s) {
        if (root == nullptr)
            return false;
        
        // Check if the complement of the current node's value exists in the set
        if (s.count(k - root->val) > 0)
            return true;
        
        // Add the current node's value to the set
        s.insert(root->val);
        
        // Recursively check for sum pairs in the left and right subtrees
        return findSumPair(root->left, k, s) || findSumPair(root->right, k, s);
    }
};
