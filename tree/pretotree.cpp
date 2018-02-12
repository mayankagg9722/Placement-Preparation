#include<iostream>
#define v 15
using namespace std;
int t=0;
struct tree{
	int data;
	struct tree * right;
	struct tree * left;
};
int findRoot(int data,int inorder[v]){
	for(int i=0;i<v;i++){
		if(inorder[i]==data){
			return i;
		}
	}
	return -1;
}
struct tree *makeTree(int start,int end,int inorder[v],
	int preorder[v]){
	if(start>end){
		return NULL;
	}

	int k=preorder[t++];
	struct tree *root=new tree();
	root->data=k;
	root->left=NULL;
	root->right=NULL;

	if(start==end){
		return root;
	}

	int l=findRoot(k,inorder);
	root->left=makeTree(start,l-1,inorder,preorder);
	root->right=makeTree(l+1,end,inorder,preorder);
	
	return root;
}
void printRoot(struct tree *root){
	if(root==NULL){
		return;
	}
	printRoot(root->left);
	cout<<root->data<<"\n";
	printRoot(root->right);
}
int main(){
	int inorder[v]={8,4,9,2,10,5,11,1,12,6,13,3,14,7,15};
	int preorder[v]={1,2,4,8,9,5,10,11,3,6,12,13,7,14,15};
	struct tree *root=makeTree(0,v-1,inorder,preorder);
	printRoot(root);
	return 0;
}