/**

669. Trim a Binary Search Tree

Given a binary search tree and the lowest and highest boundaries as L and R, trim the tree so that all its elements lies in [L, R] (R >= L). You might need to change the root of the tree, so the result should return the new root of the trimmed binary search tree.

Example 1:
Input: 
    1
   / \
  0   2

  L = 1
  R = 2

Output: 
    1
      \
       2
Example 2:
Input: 
    3
   / \
  0   4
   \
    2
   /
  1

  L = 1
  R = 3

Output: 
      3
     / 
   2   
  /
 1

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
    TreeNode* removeNode(TreeNode** root, int l, int r) {
        if(!(*root)){
            return NULL;
        }
        if((*root) && (*root)->left){
            removeNode(&(*root)->left,l,r);    
        }
        if((*root) && (*root)->right){
            removeNode(&(*root)->right,l,r);   
        }
        int k = (*root)->val;
        if(k>r){
            if((*root)->left && (*root)->left->val<=r){
                (*root)=(*root)->left;
            }else{
                (*root)=NULL;
            }
        }else if(k<l){
            if((*root)->right && (*root)->right->val>=l){
                (*root)=(*root)->right;
            }else{
                (*root)=NULL;
            }
        }
        return (*root);
    }
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(!root){
            return NULL;
        }
        removeNode(&root,L,R);
        return root;
    }
};