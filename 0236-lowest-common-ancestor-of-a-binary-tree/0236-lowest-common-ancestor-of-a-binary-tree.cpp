/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool findpath(TreeNode* root, TreeNode* node, vector<TreeNode*>& path){
        if(root==NULL)return false;
        path.push_back(root);
        if(root== node){
            return true;
        }
        int isLeft= findpath(root->left, node, path);
        int isRight= findpath(root->right, node, path);
        if(isLeft || isRight ) return true;
        path.pop_back();
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>path1;
        vector<TreeNode*>path2;
        findpath(root,p,path1);
        findpath(root,q,path2);
        TreeNode* lca= root;
        for(int i=0,j=0; i<path1.size() && j<path2.size(); i++,j++){
            if(path1[i]!= path2[j]){
                return lca;
            }
            lca= path1[i];
        }
        return lca;
    }
};