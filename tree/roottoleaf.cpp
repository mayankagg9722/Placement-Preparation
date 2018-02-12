
/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */
int number(vector<int> list){
	int n=0;
	for(int i=0;i<list.size();i++){
		n=n*10+list[i];
	}
	return n;
}
void findLeaf(Node *root,vector<int> list,int &s){
	if(root==NULL){
		return;
	}
	list.push_back(root->data);
	findLeaf(root->left,list,s);
	findLeaf(root->right,list,s);
	if(root->left==NULL && root->right==NULL){
	   	int n = number(list);
	   	s=s+n;
	    list.pop_back();    
	}
}

long long treePathsSum(Node *root){
	vector<int> list;
	int s=0;
	findLeaf(root,list,s);
    return s;
}