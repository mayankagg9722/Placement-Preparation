/**

437. Path Sum III 


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
    int sumUtil(TreeNode* root,int sum,int c){
        if(root==NULL){
            return 0;
        }
        c=c+root->val;
        return (sum==c)+sumUtil(root->left,sum,c) + sumUtil(root->right,sum,c);
    }
    int pathSum(TreeNode* root, int sum) {
        if(!root){
            return 0;
        }
        return sumUtil(root,sum,0)+pathSum(root->left,sum)+pathSum(root->right,sum);
    }
};