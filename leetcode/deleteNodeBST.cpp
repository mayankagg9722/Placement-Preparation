/**

450. Delete Node in a BST

Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.

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
    TreeNode* deleteUtil(TreeNode** root, int k){
        if(!(*root)){
            return NULL;
        }
        if((*root)->val==k){
            if((*root)->right){
                if(((*root)->left)){
                    TreeNode* temp=(*root)->right;
                    while(temp->left!=NULL){
                        temp=temp->left;
                    }
                    temp->left=(*root)->left;
                }
                (*root)=(*root)->right;
            }else if((*root)->left){
                if(((*root)->right)){
                    TreeNode* temp=(*root)->left;
                    while(temp->right!=NULL){
                        temp=temp->right;
                    }
                    temp->right=(*root)->right;
                }
                (*root)=(*root)->left;
            }else{
                (*root)=NULL;
            }
        }
        if((*root)&&(*root)->left){
            deleteUtil(&(*root)->left,k);    
        }
        if((*root)&&(*root)->right){
            deleteUtil(&(*root)->right,k);
        }
        return (*root);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root){
            return NULL;
        }
        deleteUtil(&root,key);
        return root;
    }
};