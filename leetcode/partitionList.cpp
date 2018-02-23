/*
86. Partition List

Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* left=NULL;
        ListNode* templeft=NULL;
        ListNode* right=NULL;
        ListNode* tempright=NULL;
        while(head!=NULL){
            if(head->val<x){
                if(left==NULL){
                    left=new ListNode(head->val);
                    templeft=left;
                }else{
                    templeft->next=new ListNode(head->val);
                    templeft=templeft->next;
                }
            }else{
                if(right==NULL){
                    right=new ListNode(head->val);
                    tempright=right;
                }else{
                    tempright->next=new ListNode(head->val);
                    tempright=tempright->next;
                }
            }
            head=head->next;
        }
        if(templeft!=NULL){
            templeft->next=right;
        }else{
            return right;
        }
        return left;
    }
};