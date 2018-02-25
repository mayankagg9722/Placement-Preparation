/**

116. Populating Next Right Pointers in Each Node

Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL

 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connectEndsTwo(TreeLinkNode *rootleft,TreeLinkNode *rootright){
        if(rootleft==NULL || rootright==NULL){
            return;
        }
        TreeLinkNode* rightN=rootright;
        TreeLinkNode* leftN=rootleft;
        leftN->next=rightN;
        while(leftN->right!=NULL){
            leftN=leftN->right;
            rightN=rightN->left;
            leftN->next=rightN;
        }
    }
    void connectUtilTwo(TreeLinkNode *rootleft,TreeLinkNode *rootright){
        if(rootleft==NULL || rootright==NULL){
            return;
        }
        connectEndsTwo(rootleft,rootright);
        connectUtilTwo(rootleft->left,rootleft->right);
        connectUtilTwo(rootright->left,rootright->right);
    }
    void connect(TreeLinkNode *root) {
        if(root==NULL){
            return;
        }
        connectUtilTwo(root->left,root->right);
    }
};