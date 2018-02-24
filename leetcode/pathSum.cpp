/**

112. Path Sum


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
    
    void sumUtil(TreeNode* root,int sum,int c){
        if(flag==true){
            return;
        }
        if(root==NULL){
            return;
        }
        c=c+root->val;
        if(root->left==NULL && root->right==NULL){
            if(sum==c){
                flag=true;
            }
        }
        if(flag==false){
            sumUtil(root->left,sum,c);
            sumUtil(root->right,sum,c);
        }else{
            return;
        }

    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        sumUtil(root,sum,0);
        return flag;
    }
};