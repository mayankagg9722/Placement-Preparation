/**
124. Binary Tree Maximum Path Sum

Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.

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
    int myMAX=INT_MIN;
    int findSum(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int a = findSum(root->left);
        int b = findSum(root->right);
        myMAX=max(myMAX,max(root->val,max(root->val+a+b,max(root->val+a,root->val+b))));
        return max(0,root->val+max(a,b));
    }
    int maxPathSum(TreeNode* root) {
        findSum(root);
        return myMAX;
    }
};