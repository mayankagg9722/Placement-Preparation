/**

105. Construct Binary Tree from Preorder and Inorder Traversal

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
    int t=0;
    int findInorder(vector<int> inorder,int val){
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==val){
                return i;
            }
        }
        return -1;
    }
    TreeNode* buildTreeUtil(int start,int end,vector<int>& preorder, vector<int>& inorder){
        if(start>end){
            return NULL;
        }
        int v = preorder[t++];
        TreeNode* newNode=new TreeNode(v);
        int k=findInorder(inorder,v);
        newNode->left=buildTreeUtil(start,k-1,preorder,inorder);
        newNode->right=buildTreeUtil(k+1,end,preorder,inorder);
        return newNode;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root=buildTreeUtil(0,inorder.size()-1,preorder,inorder);
        return root;
    }
};