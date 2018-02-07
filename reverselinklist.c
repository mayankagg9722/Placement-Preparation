#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};

void makeLinkList(struct Node *head,int data){
	struct Node *a=NULL;
	a=(struct Node*)malloc(sizeof(struct Node));
	a->data=data;
	a->next=NULL;
	struct Node *move=head; 
	while(move->next!=NULL){
		move=move->next;
	}
	move->next=a;
}

void reverseLinkList(struct Node **head){

	struct Node *tempNode=(struct Node*)malloc(sizeof(struct Node));
	struct Node *nextNode=NULL;
	tempNode->next=NULL;
	while((*head)->next!=NULL){
		nextNode=(*head)->next;
		tempNode->data=(*head)->data;
		(*head)->next=tempNode;
		tempNode=(*head);
		(*head)=nextNode;
	}
	tempNode->data=(*head)->data;
	(*head)=tempNode;
}

void printLinkList(struct Node *head){

	while(head->next!=NULL){
		printf("%d\n",head->data);
		head=head->next;
	}
	printf("%d\n",head->data);
}

void rotateByUnit(struct Node *head,int k){
	struct Node *kth=NULL;
	struct Node *kthone=NULL;
	struct Node *move=head;
	int length=0;
	
	while(move->next!=NULL){
		length+=1;
		if(length==k){
			kth=move;
			kthone=move->next;
		}
		move=move->next;
	}
	length+=1;
	move->next=head;
	kth->next=NULL;
	head=kthone;
	printLinkList(head);
}

void reverseInGroup(struct Node* head,int k){

	//use stack method put first k 
	//elements in stack and then pop to make reverse k elements.
}

int main(int argc, char const *argv[])
{
	struct Node *head=NULL;
	head=(struct Node*)malloc(sizeof(struct Node));
	head->data=1;
	head->next=NULL;
	makeLinkList(head,2);
	makeLinkList(head,3);
	makeLinkList(head,4);
	makeLinkList(head,5);
	makeLinkList(head,6);
	makeLinkList(head,7);
	makeLinkList(head,8);
	// printLinkList(head);
 
	// rotateByUnit(head,3);

	// reverseInGroup(head,3);

	// reverseLinkList(&head);
	// printLinkList(head);


	return 0;
}
