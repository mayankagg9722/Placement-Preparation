/**
108. Convert Sorted Array to Binary Search Tree
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.


Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5


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
    TreeNode* createUtil(vector<int> nums,int start,int end){
        if(start>end){
            return NULL;
        }
        int k = start+(end-start+1)/2;
        TreeNode* root = new TreeNode(nums[k]);
        if(start==end){
            return root;
        }
        root->left=createUtil(nums,start,k-1);
        root->right=createUtil(nums,k+1,end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root;
        int size=nums.size();
        if(size==0){
            return NULL;
        }
        return createUtil(nums,0,size-1);
    }
};