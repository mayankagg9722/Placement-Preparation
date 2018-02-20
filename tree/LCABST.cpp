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
    TreeNode* findLCABST(TreeNode* root, TreeNode* p, TreeNode* q){
        
        if(root->val>=p->val && root->val<q->val){
            cout<<"root:"<<root->val;
            return root;
        }
        
        if(root->val<p->val && root->val<q->val){
            if(root->right!=NULL)
                return findLCABST(root->right,p,q);
        }else if(root->val>p->val && root->val>q->val){
            if(root->left!=NULL)
                return findLCABST(root->left,p,q);
        }
        return root;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* data=findLCABST(root,p,q);
        return data;
    }
};