/**

113. Path Sum II

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
    void sumUtil(TreeNode* root,int sum,int c,vector<vector<int>> &a,vector<int> small){
        if(root==NULL){
            return;
        }
        small.push_back(root->val);
        c=c+root->val;
        if(root->left==NULL && root->right==NULL){
            if(sum==c){
                a.push_back(small);
            }
        }
        sumUtil(root->left,sum,c,a,small);
        sumUtil(root->right,sum,c,a,small);
        small.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> a;
        vector<int> small;
        sumUtil(root,sum,0,a,small);
        return a;
    }
};