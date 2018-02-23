/*
101. Symmetric Tree
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
*/
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
    bool check(TreeNode* leftNode,TreeNode* rightNode){
        if(leftNode==NULL && rightNode==NULL){
            return true;
        }else if(leftNode!=NULL && rightNode==NULL){
            return false;
        }else if(leftNode==NULL && rightNode!=NULL){
            return false;
        }
        if(leftNode->val==rightNode->val){
            if(!check(leftNode->left,rightNode->right)){
                return false;
            }
            if(!check(leftNode->right,rightNode->left)){
                return false;
            }
        }else{
            return false;
        }
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        return check(root->left,root->right);
    }
};