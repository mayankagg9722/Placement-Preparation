/**

160. Intersection of Two Linked Lists

Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *ha, ListNode *hb) {
        int sa=0,sb=0;
        ListNode *t=ha,*t2;
        while(t!=NULL){
            sa++;
            t=t->next;
        }
        t=hb;
        while(t!=NULL){
            sb++;
            t=t->next;
        }
        int d = abs(sa-sb);
        if(sb>sa){
            t=hb;
            while(d--){
                t=t->next;
            }
            t2=ha;
            while(t!=t2){
                t=t->next;
                t2=t2->next;
            }
            return t;
        }else{
            t=ha;
            while(d--){
                t=t->next;
            }
            t2=hb;
            while(t!=t2){
                t=t->next;
                t2=t2->next;
            }
            return t;
        }
        return NULL;
    }
};