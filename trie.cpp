#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>
using namespace std;
struct tree{
	char data;
	vector<struct tree *> vec;
};
void insert(char t,struct tree **root){
	if((*root)->vec.empty()){
		struct tree *temp=new tree;
		temp->data=t;
		(*root)->vec.push_back(temp);
		*root=temp;
		return;
	}else{
		int flag=0;
		for(int p=0;p<(*root)->vec.size();p++){
			if(t==(*root)->vec[p]->data){
				flag=1;
				(*root)=(*root)->vec[p];
				return;
			}
		}
		if(flag==0){
			struct tree *temp=new tree;
			temp->data=t;
			(*root)->vec.push_back(temp);
			*root=temp;
			return;
		}
	}
}
void print(struct tree *root){
	if(root==NULL){
		return;
	}
	for(int i=0;i<root->vec.size();i++){
		cout<<root->vec[i]->data<<"\n";
		print(root->vec[i]);
	}
}

int main()
{
	string s;
	struct tree *root=new tree;
	root->data='#';
	int n=5;
	for(int i=0;i<n;i++){
		cin>>s;
		struct tree *rootTemp=root;
		for(int j=0;j<s.length();j++){
			insert(s[j],&rootTemp);
		}
	}
	print(root);
	return 0;
}

