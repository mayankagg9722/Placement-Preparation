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
    int leftdepth(TreeNode* root){
        int h=0;
        while(root!=NULL){
        	h+=1;
            root=root->left;
        }
        return h;
    }
    int rightdepth(TreeNode* root){
        int h=0;
        while(root!=NULL){
        	h+=1;
            root=root->right;
        }
        return h;
    }    
    int countNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int ld=leftdepth(root);
        int rd=rightdepth(root);
        if(ld==rd){
            return pow(2,ld)-1;
        }else{
            return 1+countNodes(root->left)+countNodes(root->right);    
        }
        return 0;
    }
};