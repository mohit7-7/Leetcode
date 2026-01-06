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
    int maxLevelSum(TreeNode* root) {
        int maxsum = -1e9;
        int level = 0 ;
        queue<pair<TreeNode*,int>>q;
        q.push({root,1});
        while(!q.empty()){
            int currlvl = q.front().second;
            int currsum =0;
            while(!q.empty() && q.front().second== currlvl){
                TreeNode*node = q.front().first;

                if(node-> left){
                    q.push({node->left,currlvl+1});
                }
                if(node-> right){
                    q.push({node->right,currlvl+1});
                }

                int val = q.front().first->val;
                currsum += val;
                q.pop();
                
            }
            if(currsum > maxsum){
                maxsum= currsum ;
                level = currlvl;
            }
        }
        return level;
    }
};