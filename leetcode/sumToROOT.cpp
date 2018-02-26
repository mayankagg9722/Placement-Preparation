/**

129. Sum Root to Leaf Numbers

Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.



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
    int s=0;
    int finalsum=0;
    void findNo(TreeNode* root){
        if(!root){
            return;
        }
        s=(s*10)+root->val;
        if(!root->right && !root->left){
            finalsum+=s;
        }
        findNo(root->left);
        findNo(root->right);
        s=(s-root->val)/10;
    }
    int sumNumbers(TreeNode* root) {
        if(!root){
            return 0;
        }
        findNo(root);
        return finalsum;
    }
};