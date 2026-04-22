class Solution {
public:
    int inOrder(TreeNode* root, int& k) {
        if (!root) return -1;  // Base case
        
        // Search in left subtree
        int left = inOrder(root->left, k);
        if (left != -1) return left;  // Found in left
        
        // Process current node
        k--;
        if (k == 0) return root->val;  // Found!
        
        // Search in right subtree
        return inOrder(root->right, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        return inOrder(root, k);
    }
};