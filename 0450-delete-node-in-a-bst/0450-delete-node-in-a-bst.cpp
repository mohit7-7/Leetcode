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
    
    TreeNode* IS(TreeNode*root){
        while(root->left !=NULL){
            root= root->left;
        }
        return root;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val > key){
            root->left= deleteNode(root->left, key);
        }
        else if(root->val< key){
            root->right= deleteNode(root->right, key);
        }
        
        // mil gyi node
        else{
            if(root->left == NULL && root->right== NULL){
                delete root;
                return NULL;
            }
            if(root->left && root->right){
                TreeNode* todelete= IS(root->right);
                root-> val = todelete->val;
                root->right= deleteNode(root->right,todelete->val);
                return root;
            }
            return root->left? root->left: root->right;
        }
        return root;
    }
};