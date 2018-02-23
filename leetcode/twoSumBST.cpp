/*
653. Two Sum IV - Input is a BST

Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

Example 1:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

Output: True
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
    bool flag=false;
    void check(TreeNode* head,TreeNode* root,int n){
        if(head==NULL){
            return;
        }
        if(head->val==n && head!=root){
            flag=true;
            return;
        }
        if(flag==false){
            if(n>head->val){
                check(head->right,root,n);
            }else{
                check(head->left,root,n);
            }
        }else{
            return;
        }
    }
    void traverse(TreeNode* root,TreeNode* head,int k){
        if(flag==true){
            return;
        }
        if(root==NULL){
            return;
        }
        check(head,root,k-(root->val));
        if(flag==false){
            traverse(root->left,head,k);
        }else{
            return;
        }
        if(flag==false){
        traverse(root->right,head,k);    
        }else{
            return;
        }
    }
    bool findTarget(TreeNode* root, int k) {
        traverse(root,root,k);
        return flag;
    }
};