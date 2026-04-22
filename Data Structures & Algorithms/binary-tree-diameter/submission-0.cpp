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
    int maxDiameter = 0;  // Track maximum diameter
    
    int height(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        
        // Calculate height of left and right subtrees
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        
        // Diameter at this node = left height + right height
        int currentDiameter = leftHeight + rightHeight;
        
        // Update maximum diameter
        maxDiameter = max(maxDiameter, currentDiameter);
        
        // Return height of current node
        return 1 + max(leftHeight, rightHeight);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return maxDiameter;
    }
    
};
