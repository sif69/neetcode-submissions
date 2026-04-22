class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN, LONG_MAX);
    }
    
private:
    bool validate(TreeNode* root, long minVal, long maxVal) {
        // Base case: empty tree is valid
        if (!root) return true;
        
        // Check if current node violates BST property
        if (root->val <= minVal || root->val >= maxVal) {
            return false;
        }
        
        // Recursively validate left and right subtrees
        // Left subtree: all values must be < root->val
        // Right subtree: all values must be > root->val
        return validate(root->left, minVal, root->val) &&
               validate(root->right, root->val, maxVal);
    }
};