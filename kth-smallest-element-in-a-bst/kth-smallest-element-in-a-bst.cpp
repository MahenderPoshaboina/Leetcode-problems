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
    int ans;
    int kthSmallest(TreeNode* root, int k) {
        find(root, k);
        return ans;
    }
    void find(TreeNode* root, int &k){
        if(!root || !k) return ;

        find(root->left, k);

        if(--k ==0){
            ans= root->val;
            return;
        }

        find(root->right, k);
    }
};