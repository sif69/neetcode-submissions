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
    int l,r,k;
    int Ht(TreeNode* root){
            if(!root) return 0;
            int leftH = Ht(root->left);
            int rightH = Ht(root->right);
           
            return 1+max(leftH,rightH);
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        
        int currentL = Ht(root->left), currentR = Ht(root->right);
        if(abs(currentL-currentR)>1) return false;
        if(!isBalanced(root->left)||!isBalanced(root->right)) return false;
        return true;

        
    }
};