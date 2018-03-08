/**

199. Binary Tree Right Side View

Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].

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
    queue<TreeNode *> s;
    vector<int> a;
    void bfs(){
        queue<TreeNode *> ns;
        while(!s.empty()){
            TreeNode* n = s.front();
            if(n->left){
                ns.push(n->left);
            }
            if(n->right){
                ns.push(n->right);
            }
            s.pop();
        }
        s=ns;
    }
    vector<int> rightSideView(TreeNode* root) {
        if(!root){
            return a;
        }
        s.push(root);
        while(!s.empty()){
            a.push_back((s.back())->val);
            bfs();
        }
        return a;
    }
};