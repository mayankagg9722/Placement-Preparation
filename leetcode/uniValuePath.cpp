/**

687. Longest Univalue Path

Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.

Note: The length of path between two nodes is represented by the number of edges between them.

Example 1:

Input:

              5
             / \
            4   5
           / \   \
          1   1   5
Output:2

Example 2:

Input:

              1
             / \
            4   5
           / \   \
          4   4   5
Output:2

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
    int m=INT_MIN;
    int findUni(TreeNode* root,int val)
    {
        if(root==NULL){
            return 0;
        }
        int p=findUni(root->left,root->val);
        int q=findUni(root->right,root->val);
        int right=0,left=0;
        if(root->left!=NULL && root->left->val==root->val){
            left+=p+1;
        }
        if(root->right!=NULL && root->right->val==root->val){
            right+=q+1;
        }
        m=max(m,left+right);
        return max(left,right);
    }
    int longestUnivaluePath(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        return findUni(root,root->val);
    }
};