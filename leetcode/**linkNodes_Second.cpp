/**

117. Populating Next Right Pointers in Each Node II

Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL

 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    TreeLinkNode * connectEnds(TreeLinkNode *root){
        if(!root){
            return NULL;
        }
        if(root->left){
            return root->left;
        }
        if(root->right){
            return root->right;
        }
        return connectEnds(root->next);
    }
     void connectUtilTwo(TreeLinkNode *root) {
        if (!root){
            return;
        }
        if (root->left){
            if (root->right){
                root->left->next = root->right;
            }
            else{
                root->left->next = connectEnds(root->next);
            }
        }
        if (root->right) {
            root->right->next = connectEnds(root->next);
        }
        connectUtilTwo(root->right);
        connectUtilTwo(root->left);
    }
    void connect(TreeLinkNode *root) {
        if(!root){
            return;
        }
        connectUtilTwo(root);
    }
};