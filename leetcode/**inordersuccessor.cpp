#include<stdc++.h>
using namespace std;
 
// A Binary Tree Node
struct Node
{
    int data;
    struct Node *left, *right;
};
 
Node* temp = new Node;
 
Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node* leftMostNode(Node* node)
{
    while (node != NULL && node->left != NULL)
        node = node->left;
    return node;
}

Node* rightMostNode(Node* node)
{
    while (node != NULL && node->right != NULL)
        node = node->right;
    return node;
}

Node* findInorderRecursive(Node* root, Node* x)
{
    if (root==NULL)
        return NULL;

    cout<<"root: "<<root->data<<endl;
    cout<<"checking: "<<x->data<<endl;

    if(root->left!=NULL && root->left==x){
        cout<<"found left"<<endl;
        cout<<"Inorder Successor: "<<root->data<<endl;
        return root;
    }

    if(root->right!=NULL && root->right==x){
        cout<<"found right"<<endl;
        return root;
    }
 
    temp = findInorderRecursive(root->left,x);
    if(temp!=NULL){
        if(temp->left!=x){
            findInorderRecursive(root,temp);
        }
    }
    temp = findInorderRecursive(root->right,x);
    if(temp!=NULL){
        if(temp->left!=x){
            findInorderRecursive(root,temp);
        }
    }
    return NULL;
}

void inorderSuccesor(Node* root, Node* x)
{
    if (x->right != NULL)
    {
        Node* inorderSucc = leftMostNode(x->right);
        cout<<"Inorder Successor of "<<x->data<<" is ";
        cout<<inorderSucc->data<<"\n";
    }
    if (x->right == NULL)
    {    
        int f = 0;
         
        Node* rightMost = rightMostNode(root);
 
        if (rightMost == x)
            cout << "No inorder successor! Right most node.\n";
        else
            findInorderRecursive(root, x);
    }
}
int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
    inorderSuccesor(root, root->left->right);
    return 0;
}