/**

102. Binary Tree Level Order Traversal

 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// ####################### BEST WAY #######################

class Solution {
public:
    void levelOrderUtil(TreeNode* root,vector<vector<int>> &b,int depth){
        if(root==NULL){
            return;
        }
        if(b.size()<=depth){
            vector<int> small;
            b.push_back(small);
        }
        b[depth].push_back(root->val);
        levelOrderUtil(root->left,b,depth+1);
        levelOrderUtil(root->right,b,depth+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> b;
        if(root==NULL){
            return b;
        }
        levelOrderUtil(root,b,0);
        return b;
    }
};

// ####################### BEST WAY #######################

class Solution {
public:
    void levelOrderUtil(vector<TreeNode*> a,vector<vector<int>> &b){
        if(a.size()==0){
            return;
        }
        vector<TreeNode*> :: iterator it;
        vector<int> dts;
        it=a.begin();
        int k=a.size();
        int c=0;
        while(c<k){
            TreeNode *r=*it;
            dts.push_back(r->val);
            if((r->left)!=NULL){
                a.push_back(r->left);    
            }
            if((r->right)!=NULL){
                a.push_back(r->right);
            }            
            c++;
            it++;
        }
        a.erase(a.begin(),a.begin()+k);
        b.push_back(dts);
        levelOrderUtil(a,b);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> b;
        if(root==NULL){
            return b;
        }
        vector<TreeNode*> a;
        a.push_back(root);
        levelOrderUtil(a,b);
        return b;
    }
};