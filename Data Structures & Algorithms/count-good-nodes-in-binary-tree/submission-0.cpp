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
    
    int ans(TreeNode* root ,int k){
            if(!root) return 0;
            int current = 0;
            if((root->val) >= k) {
                current = 1;
                k = root->val;
            }
         
         return current + ans(root->left, k) + ans(root->right, k);
            
    }
    int goodNodes(TreeNode* root) {
        int mn = INT_MIN;
        if(!root) return 0;
        return ans(root, mn);
    }
};