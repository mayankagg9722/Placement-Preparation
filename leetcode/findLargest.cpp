/**
515. Find Largest Value in Each Tree Row

Pick One
You need to find the largest value in each row of a binary tree.

Example:
Input: 

          1
         / \
        3   2
       / \   \  
      5   3   9 

Output: [1, 3, 9]


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
    map<int,int> mp;
    void util(TreeNode *root,int k){
        if(!root){
            return;
        }
        if(mp.find(k)!=mp.end()){
            mp[k]=max(mp[k],root->val);    
        }else{
            mp[k]=root->val;
        }
        util(root->left,k+1);
        util(root->right,k+1);
    }
    vector<int> largestValues(TreeNode* root) {
        util(root,0);
        vector<int> a;
        for(pair<int,int> p:mp){
            a.push_back(p.second);
        }
        return a;
    }
};