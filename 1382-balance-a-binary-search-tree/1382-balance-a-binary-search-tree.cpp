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
    void inorder(TreeNode* root, vector<int>&nums){
        if(root==NULL)return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }
    
    TreeNode* balancing(vector<int>&nums, int start, int end){
        if(start> end) return NULL;
        int mid= (start+end)/2;
        TreeNode* currnode= new TreeNode(nums[mid]);
        currnode ->left= balancing(nums,start,mid-1);
        currnode->right= balancing(nums,mid+1,end);
        return currnode;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nums;
        inorder(root,nums);
        int n= nums.size()-1;
        return balancing(nums,0,n);
    }
};