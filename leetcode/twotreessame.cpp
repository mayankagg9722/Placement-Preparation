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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL){
            return true;
        }
        if(p!=NULL && q==NULL){
            return false;
        }
        if(p==NULL && q!=NULL){
            return false;
        }
        
        if(p->val!=q->val){
            return false;
        }
        
        bool t=isSameTree(p->left,q->left);
        bool f=isSameTree(p->right,q->right);
        if(!t){
            return false;
        }
        if(!f){
            return false;
        }
        return true;
    }
    
};