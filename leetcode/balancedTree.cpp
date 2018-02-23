/**

110. Balanced Binary Tree

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the depth of the two subtrees of every node never differ by more than 1.


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
    void findDepth(TreeNode* root,int k,int &h){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            if(k>h){
                h=k;    
            }
        }
        findDepth(root->left,k+1,h);
        findDepth(root->right,k+1,h);
    }
    bool findBalaced(TreeNode *root){
        if(root==NULL){
            return true;
        }
        int lh= 0;
        findDepth(root->left,1,lh);
        int rh= 0;
        findDepth(root->right,1,rh);
        if(abs(lh-rh)>1){
            return false;
        }
        if(!findBalaced(root->left)){
            return false;
        }
        if(!findBalaced(root->right)){
            return false;
        }
        return true;
    }
    bool isBalanced(TreeNode* root) {
        return findBalaced(root);
    }
};