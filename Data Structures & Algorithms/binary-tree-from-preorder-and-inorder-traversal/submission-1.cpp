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
    map<int,int>mp1,mp2;
    int mid;
    TreeNode* BT(vector<int>& preorder, vector<int>& inorder){
                if(preorder.empty()) return nullptr;
                TreeNode * root = new TreeNode(preorder[0]);
               
                for(int i=0; i<inorder.size(); i++) if(inorder[i] == preorder[0]) { mid = i; break; }
    vector<int> preLeft(preorder.begin() + 1, preorder.begin() + mid + 1);
    vector<int> inLeft(inorder.begin(), inorder.begin() + mid);
    
 
    vector<int> preRight(preorder.begin() + mid + 1, preorder.end());
    vector<int> inRight(inorder.begin() + mid + 1, inorder.end());
    
   
                root->left = BT(preLeft, inLeft);
                root->right = BT(preRight, inRight);
          return root;      

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         int i;
         for(i=0;i<preorder.size();i++){
             mp1[inorder[i]]  = i;
             
         }

        return BT(preorder,inorder);
    }
};