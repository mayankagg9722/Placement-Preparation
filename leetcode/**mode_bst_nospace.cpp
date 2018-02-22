/*
501. Find Mode in Binary Search Tree

Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
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
    int prev=-1;
    int count=1;
    int max=0;
    void traverse(TreeNode *root, vector<int> &a){
        if(root==NULL){
            return;
        }
        traverse(root->left,a);
        if(prev!=-1){
            if(prev==root->val){
                count++;
            }else{
                count=1;
            }
        }
        if(max<count){
            max=count;
            a.clear();
            a.push_back(root->val);
        }else if(count==max){
            a.push_back(root->val);
        }
        prev=root->val;
        traverse(root->right,a);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> a;
        traverse(root,a);
        return a;
    }
};