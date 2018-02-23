/**
104. Maximum Depth of Binary Tree
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
    int max= INT_MIN;
    void findDepth(TreeNode* root,int k){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            if(k>max){
                max=k;    
            }
        }
        findDepth(root->left,k+1);
        findDepth(root->right,k+1);
    }
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        findDepth(root,1);
        return max;
    }
};