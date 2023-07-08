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
    TreeNode* construct(vector<int>& preorder, int &idx, int MinValue, int MaxValue){
       if(idx> preorder.size()-1 || preorder[idx]<MinValue || preorder[idx]> MaxValue ) return nullptr;

       TreeNode* root = new TreeNode(preorder[idx]);

       idx++;
       root->left = construct(preorder, idx, MinValue, root->val);
       root->right = construct(preorder, idx, root->val, MaxValue);
       return root;

    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx=0;
        return construct(preorder, idx, INT_MIN, INT_MAX);
    }
};