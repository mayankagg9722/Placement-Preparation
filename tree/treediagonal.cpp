#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<limits.h>
using namespace std;

struct Node{
	int data;
	struct Node *left;
	struct Node *right;
};

// ############## BST ##############
//BST
struct Node * insertNodeBST(int data,struct Node *root){

	if(root==NULL){
		root=(struct Node *)malloc(sizeof(struct Node));
		root->data=data;
		root->left=NULL;
		root->right=NULL;
		return root;
	}

	if(root->data<data){
		root->right=insertNodeBST(data,root->right);
	}else{
		root->left=insertNodeBST(data,root->left);
	}

	return root;

}

// ############## BST ##############

// ############## TREE Traversal ##############

void inorder(struct Node *root){
	if(root==NULL){
		return;
	}
	inorder(root->left);
	printf("%d\n",root->data);
	inorder(root->right);
}

void bfs(struct Node *root){

	vector<struct Node *> arr;
	if(root==NULL){
		printf("NO VALUES\n");
		return;
	}else{
		arr.push_back(root);
		while(arr.size()>0){
			printf("%d\n",arr[0]->data);
			if(arr[0]->left!=NULL){
				arr.push_back(arr[0]->left);
			}
			if(arr[0]->right!=NULL){
				arr.push_back(arr[0]->right);
			}
			arr.erase(arr.begin());
		}
	}
}

// ############## TREE Traversal ##############

// ############## DIAGONAL TREE ##############
struct hashmap{
	int key;
	vector<int> value;
};

vector<struct hashmap > hashArray;

void findAndPut(struct Node *root,int s){
	if(hashArray.size()==0){
		struct hashmap initialhash;
		initialhash.key=s;
		(initialhash.value).push_back(root->data);
		hashArray.push_back(initialhash);
	}
	else{
		int flag=0;
		int pos=0;
		for(int i=0;i<hashArray.size();i++){
			struct hashmap hashI=hashArray[i];
			if(hashI.key==s){
				flag=1;
				pos=i;
				break;
			}
		}

		if(flag==1){
			struct hashmap hashI=hashArray[pos];
			(hashI.value).push_back(root->data);
			hashArray[pos]=hashI;
		}else if(flag==0){
			struct hashmap initialhash;
			initialhash.key=s;
			(initialhash.value).push_back(root->data);
			hashArray.push_back(initialhash);
		}
	}
}

void diagonal(struct Node *root,int s){
	
	if(root==NULL){
		return;
	}
	findAndPut(root,s);
	diagonal(root->right,s);
	diagonal(root->left,s-1);
}

void printhash(){

	for(int i=0;i<hashArray.size();i++){
		struct hashmap hashI=hashArray[i];
		printf("Key:%d\n",hashI.key);
		printf("Values:\n");
		// printf("size of hashi = %d\n",(int)(hashI.value.size()));
		for(int j=0;j<hashI.value.size();j++){
			printf("%d\n",hashI.value[j]);
		}
	}

}

// ############## DIAGONAL TREE ##############

// ############## Maximum distance between two leaves ##############




int maxBWTwoLeaf(struct Node *root,int *res){

	if(root==NULL){
		return 0;
	}

	if(root->left==NULL && root->right==NULL){
		return root->data;
	}

	int ls=maxBWTwoLeaf(root->left,res);
	int rs=maxBWTwoLeaf(root->right,res);

	if(root->left!=NULL && root->right!=NULL){
		*res=max(*res,ls+rs+root->data);
		return max(ls,rs)+root->data;
	}

	return (!root->left)? rs + root->data:
                          ls + root->data;
}




// ############## Maximum distance between two leaves ##############


// ############## Maximum path ##############


int maxDistAnyNode(struct Node *root,int *res){

	if(root==NULL){
		return 0;
	}

	int ls=maxDistAnyNode(root->left,res);
	int rs=maxDistAnyNode(root->right,res);


	int single_max=max(max(ls,rs)+root->data,root->data);

	int max_top=max(single_max,ls+rs+root->data);

	*res=max(*res,max_top);

	return single_max;
}

// ############## Maximum path ##############

// ############## Diameter ##############

int height(struct Node *root){
	if(root==NULL){
		return 0;
	}

	int k=1+max(height(root->left),height(root->right));

	return k;
}

int diameter(struct Node *root){

	if(root==NULL){
		return -1;
	}

	int lh=height(root->left);
	int rh=height(root->right);

	int leftDia=diameter(root->left);
	int rightDia=diameter(root->right);
	
	return max((1+lh+rh),max(leftDia,rightDia));
}

// ############## Diameter ##############

int main()
{
	struct Node *root=NULL;
	root=insertNodeBST(10,root);
	insertNodeBST(5,root);
	insertNodeBST(6,root);
	insertNodeBST(3,root);
	insertNodeBST(12,root);
	insertNodeBST(11,root);
	insertNodeBST(13,root);
	insertNodeBST(2,root);
	insertNodeBST(4,root);
	insertNodeBST(14,root);
	insertNodeBST(15,root);

	int res=INT_MIN;
	// maxBWTwoLeaf(root,&res);
	// printf("%d\n",res);

	// maxDistAnyNode(root,&res);
	// printf("%d\n",res);

	// res=height(root);
	// printf("%d\n",res);

	res=diameter(root);
	printf("%d\n",res);

	// diagonal(root,0);
	// printhash();

	// inorder(root);
	// bfs(root);

	return 0;
}



	// int *array=(int *)malloc(10*sizeof(int));

	// for(int i=0;i<7;i++){
	// 	*(array+i)=(i+1);
	// }

	// for(int i=0;i<7;i++){
	// 	int data=*(array+i);
	// 	root=insertNodeBT(data,root);
	// 	// printf("%d\n",data);
	// }
