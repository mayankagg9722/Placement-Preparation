/**
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
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
    int c=0;
    int ele;
    void findUtil(TreeNode* root,int k){
        if(!root || c==k){
            return;
        }
        findUtil(root->left,k);
        c++;
        if(c==k){
            ele=root->val;
            return;
        }
        findUtil(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root){
            return 0;
        }
        findUtil(root,k);
        return ele;
    }
};