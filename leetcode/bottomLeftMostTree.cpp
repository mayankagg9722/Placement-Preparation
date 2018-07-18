/**
513. Find Bottom Left Tree Value

Given a binary tree, find the leftmost value in the last row of the tree.

Example 1:
Input:

    2
   / \
  1   3

Output:
1
Example 2: 
Input:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

Output:
7
Note: You may assume the tree (i.e., the given root node) is not NULL.




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
    int height=INT_MIN;
    int ans;
    void util(TreeNode* root,int h){
        if(root==NULL){
            return;
        }
        int x=h;
        int val;
        TreeNode* temp=root;
        while(temp!=NULL){
            x++;
            val=temp->val;
            temp=temp->left;
        }
        if(height<x){
            height=x;
            ans=val;
        }
        util(root->left,h+1);
        util(root->right,h+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        util(root,1);
        return ans;
    }
};