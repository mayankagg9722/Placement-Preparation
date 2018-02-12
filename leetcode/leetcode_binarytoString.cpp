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
    void preOrder(TreeNode* t,string &s){
        if(t==NULL){
            return;
        }
        s.append(to_string(t->val));
        if(t->left==NULL && t->right!=NULL){
             if(t->left==NULL){
                s.append("(");
                preOrder(t->left,s); 
                s.append(")");
            }
            if(t->right!=NULL){
                s.append("(");
                preOrder(t->right,s); 
                s.append(")");
            }
        }else if(t->left!=NULL && t->right==NULL){
            if(t->left!=NULL){
            s.append("(");
            preOrder(t->left,s); 
            s.append(")");
            }
            if(t->right==NULL){
            preOrder(t->right,s); 
            }
        }else{
            if(t->left!=NULL){
                s.append("(");
                preOrder(t->left,s); 
                s.append(")");
            }
            if(t->right!=NULL){
                s.append("(");
                preOrder(t->right,s); 
                s.append(")");
            }
        }
        
    }
    
    string tree2str(TreeNode* t) {
        string s;
        preOrder(t,s);
        return s;
    }
};