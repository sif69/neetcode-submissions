class Solution {
public:
    int cnt = 0;
    TreeNode* ans(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root) return nullptr;
        if (root->val > p->val && root->val > q->val) {
            return ans(root->left, p, q);
        }
        if (root->val < p->val && root->val < q->val) {
            return ans(root->right, p, q);
        }
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return ans(root,p,q);
    }
};