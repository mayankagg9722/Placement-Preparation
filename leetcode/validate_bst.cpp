
/*
98. Validate Binary Search Tree
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
    bool flag=true;
    void findMax(TreeNode* root,int &max){
        if(root==NULL){
            return;
        }
        if(max<root->val){
            max=root->val;
        }
        findMax(root->left,max);
        findMax(root->right,max);
    }
    
    void findMin(TreeNode* root,int &min){
        if(root==NULL){
            return;
        }
        if(min>root->val){
            min=root->val;
        }
        findMin(root->left,min);
        findMin(root->right,min);
    }
    
    void validate(TreeNode* root){
        if(root==NULL || flag==false){
            return;
        }
        int max=INT_MIN;
        int min=INT_MAX;
        if(root->left!=NULL){
            findMax(root->left,max);  
            cout<<"max:"<<max<<endl;
            if(max>=root->val){
                flag=false;
                return;
            }
        }
        if(root->right!=NULL){
            findMin(root->right,min); 
            cout<<"min:"<<min<<endl;
            if(min<=root->val){
                flag=false;
                return;
            }
        }
        validate(root->left);
        validate(root->right);
    }
    
    bool isValidBST(TreeNode* root) {
        validate(root);
        return flag;
    }
};