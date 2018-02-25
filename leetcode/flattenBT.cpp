/**

114. Flatten Binary Tree to Linked List

Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

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
    void flattenUtil(TreeNode** root){
        if((*root)==NULL){
            return;
        }
        if((*root)->left!=NULL){
            TreeNode* lefttemp=(*root)->left;
            TreeNode* righttemp=(*root)->right;
            (*root)->right=lefttemp;
            while(lefttemp->right!=NULL){
                lefttemp=lefttemp->right;
            }
            lefttemp->right=righttemp;
            (*root)->left=NULL;
        }
        flattenUtil(&((*root)->right));
    }
    void flatten(TreeNode* root) {
        flattenUtil(&root);
    }
};