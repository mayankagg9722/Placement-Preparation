/*
404. Sum of Left Leaves

Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.*/
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
    int s=0;
    void findUtil(TreeNode* root){
        if(!root){
            return;
        }
        TreeNode *temp = root->left;
        if(temp!=NULL && temp->left==NULL && temp->right==NULL){
            s+=temp->val;
        }
        findUtil(root->left);
        findUtil(root->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        findUtil(root);
        return s;
    }
};