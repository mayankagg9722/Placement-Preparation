/**
234. Palindrome Linked List

Given a singly linked list, determine if it is a palindrome.

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    long long int a=0;
    long long int b=0;
    bool isPalindrome(ListNode* head) {
        ListNode* temp=head;
        while(temp!=NULL){
            a=a*10+(temp->val);
            temp=temp->next;
        }
        temp=NULL;
        while(head!=NULL){
            ListNode* r = head->next;
            head->next=temp;
            temp=head;
            head=r;
        }
        while(temp!=NULL){
            b=b*10+(temp->val);
            temp=temp->next;
        }
        cout<<a<<endl;
        cout<<b<<endl;
        if(a==b){
            return true;
        }
        return false;
    }
};