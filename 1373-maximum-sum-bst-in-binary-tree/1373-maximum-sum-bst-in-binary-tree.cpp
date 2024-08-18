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

static int maxsum;
class Solution {
public:
    class Info{
        public:
        int sum;
        int min;
        int max;
        bool isBST;
        
        Info(int sum, int min, int max, bool isbst){
            this->sum= sum;
            this->min= min;
            this->max= max;
            this-> isBST= isbst;
        }
    };
    
    Info* helper(TreeNode*root){
        if(root==NULL){
            return new Info(0,INT_MAX,INT_MIN,true);
        }
        Info* leftinfo= helper(root->left);
        Info* rightinfo= helper(root->right);
        int currsum= leftinfo->sum+ rightinfo->sum+ root->val;
        int currmin= min(root->val, min(leftinfo->min, rightinfo->min));
        int currmax= max(root->val, max(leftinfo->max, rightinfo->max));
        
        if(leftinfo->isBST && rightinfo->isBST
        && root->val > leftinfo->max
        && root->val < rightinfo->min){
            maxsum= max(maxsum,currsum);
            return new Info(currsum, currmin , currmax, true);
        }
        return new Info(currsum, currmin, currmax, false);
    };
    
    int maxSumBST(TreeNode* root) {
        maxsum=0;
        Info* ans= helper(root);
        return maxsum;
    }
};