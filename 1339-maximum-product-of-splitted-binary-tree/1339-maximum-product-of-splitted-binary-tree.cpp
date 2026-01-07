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
    long maxP;
    long SUM;
    
    int totalsum(TreeNode* root){
        if(root==NULL) return 0;

        int left = totalsum(root->left);
        int right = totalsum(root->right);
        long subsum = root->val + left + right;
        
        long remainsum = SUM - subsum;
        maxP = max(maxP , subsum*remainsum);
        return subsum;
    }

    int maxProduct(TreeNode* root) {
        if(root==NULL) return 0;
        maxP = 0;
        SUM = totalsum(root);

        totalsum(root);
        return maxP%1000000007;
    }
};