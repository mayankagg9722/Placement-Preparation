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
    int m=0;
    int findDia(TreeNode* root){
        if(!root){
            return 0;
        }
        int a = findDia(root->left);
        int b = findDia(root->right);
        m=max(m,a+b);
        return 1+max(a,b);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        findDia(root);
        return m;
    }
};