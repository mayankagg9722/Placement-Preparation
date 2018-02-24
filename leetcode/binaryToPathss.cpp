/**

257. Binary Tree Paths

Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]

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
    string vectostring(vector<int> small){
        string myString="";
        for(int i=0;i<small.size()-1;i++){
            myString.append(to_string(small[i]));
            myString.append("->");
        }
        myString.append(to_string(small[small.size()-1]));
        return myString;
    }
    void findPath(TreeNode* root,vector<string> &a,vector<int> small){
        if(root==NULL){
            return;
        }
        small.push_back(root->val);
        if(!root->left && !root->right){
            string myString = vectostring(small);
            a.push_back(myString);
        }
        findPath(root->left,a,small);
        findPath(root->right,a,small);
        small.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> a;
        if(root==NULL){
            return a;
        }
        vector<int> small;
        findPath(root,a,small);
        return a;
    }
};