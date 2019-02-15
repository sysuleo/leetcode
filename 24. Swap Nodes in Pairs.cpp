/*
Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 /*Pointer-pointer pp points to the pointer to the current node. So at first, pp points to head, and later it points to the next field of ListNodes. Additionally, for convenience and clarity, pointers a and b point to the current node and the next node.

We need to go from *pp == a -> b -> (b->next) to *pp == b -> a -> (b->next). The first three lines inside the loop do that, setting those three pointers (from right to left). The fourth line moves pp to the next pair.
*/

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode ** pp=&head;
        ListNode * a,*b;
        while((a=*pp)&&(b=a->next)){
            a->next=b->next;
            b->next=a;
            *pp=b;
            pp=&(a->next);
        }
        return head;
    }
};
