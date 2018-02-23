/*
95. Unique Binary Search Trees II
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/
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
    vector<TreeNode*> genrateHelper(int s,int e){
        vector<TreeNode*> res;
        if(s>e){
            res.push_back(NULL);
            return res;
        }
        for(int i=s;i<=e;i++){
            vector<TreeNode*> left =  genrateHelper(s,i-1);
            vector<TreeNode*> right =  genrateHelper(i+1,e);
            for(int j=0;j<(int)left.size();j++){
                for(int k=0;k<(int)right.size();k++){
                    TreeNode* tree = new TreeNode(i);
                    tree->left=left[j];
                    tree->right=right[k];
                    res.push_back(tree);
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n==0){
            return vector<TreeNode*>(0);
        }
        return genrateHelper(1,n);
    }
};