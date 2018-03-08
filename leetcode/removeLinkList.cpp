/**

203. Remove Linked List Elements

Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* h, int v) {
        ListNode* t1 = NULL;
        while(h!=NULL && h->val==v){
            h=h->next;
        }
        t1=h;
        while(h!=NULL){
            ListNode* temp = h->next;
            while(temp!=NULL && temp->val==v){
                temp=temp->next;
            }
            h->next=temp; 
            h=h->next;
        }
        return t1; 
    }
};