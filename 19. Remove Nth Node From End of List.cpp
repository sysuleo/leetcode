/**
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr) return head;
        if(n<0) return NULL;
        ListNode*pre=head;
        ListNode*FindEnd=head;
        ListNode*Tobedelete=nullptr;
        while(n){
            FindEnd=FindEnd->next;
            n--;
        }
        if(FindEnd==nullptr) return head->next;
        while(FindEnd->next!=nullptr){
            FindEnd=FindEnd->next;
            pre=pre->next;
        }
        Tobedelete=pre->next;
        pre->next=Tobedelete->next;
        //free(Tobedelete);
        return head;
    }
};



class Solution {//other's solution
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode ** entry= &head;
    ListNode * last = head;
    for(int i=0;i<n;++i){
      last=last->next;
    }
    while(last){
      last=last->next;
      entry = &(*entry)->next;
    }
    * entry = (*entry)->next;
    return head;
  }
};
