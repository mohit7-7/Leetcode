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
    TreeNode* helper(vector<int>& nums, int low,int high){
        if(low>high)return NULL;
        int mid= low+(high-low)/2;
        TreeNode* currnode= new TreeNode(nums[mid]);
        currnode-> left= helper(nums, low, mid-1);
        currnode-> right= helper(nums,mid+1,high);
        return currnode;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n= nums.size()-1;
        return helper(nums,0,n);
    }
};