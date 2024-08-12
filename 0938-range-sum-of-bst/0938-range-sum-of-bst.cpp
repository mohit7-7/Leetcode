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
    void sumr(TreeNode* root, int low, int high, int &sum){
        if(root==NULL) return ;
        if(low<= root->val && root->val <=high){
            sum+=root->val;
            sumr(root->left, low, high, sum);
            sumr(root->right, low, high, sum);
        }
        else if(root->val<low){
            sumr(root->right, low, high, sum);
        }
        else{
            sumr(root->left, low, high, sum);
        }
        
    }
    
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
        sumr(root, low, high, sum);
        return sum;
    }
};