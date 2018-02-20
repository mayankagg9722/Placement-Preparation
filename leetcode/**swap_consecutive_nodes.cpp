/**
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.


 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };

 */
class Solution {
public:
    ListNode* swapPairs(ListNode* h) {
        if(h==NULL){
            return h;
        }
        ListNode **p=&h;
        ListNode *a;
        ListNode *b;
        while((a=*p) && (b=a->next)){
            a->next=b->next;
            b->next=a;
            *p=b;
            p=&(a->next);
        }
        return h;
    }
};


//java solution below

// class Solution {
//     public ListNode swapPairs(ListNode head) {
//         if(head==null || head.next==null) return head;
//     ListNode newHead = head.next, a=head,b=a.next,pre = null;
//     while(a!=null && b!=null){
//       a.next = b.next;
//       b.next = a;
//       if(pre!=null) pre.next = b;
//       if(a.next==null) break;
//       b = a.next.next;
//       pre = a;
//       a = a.next;
//     }
//     return newHead;
//     }
// }