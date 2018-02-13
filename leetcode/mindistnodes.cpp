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
    int min=INT_MAX;
    vector<int> a;
    void findMin(TreeNode* root){
        if(root==NULL){
            return;
        }
        findMin(root->left);
        a.push_back(root->val);
        findMin(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        findMin(root);
        for(int i=0;i<a.size()-1;i++){
            if(min>(a[i+1]-a[i])){
                min=a[i+1]-a[i];
            }
        }
        return min;
    }
};