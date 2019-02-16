/*Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Note:

    Only constant extra memory is allowed.
    You may not alter the values in the list's nodes, only nodes itself may be changed.

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1) return head;
        if(!hasK(head,k)) return head;
        ListNode * new_head=new ListNode(0);
        new_head->next=head;
        ListNode * pre=new_head;
        ListNode *pos=head;
        while(hasK(pos,k)){
            for(int i=0;i<k-1;i++){
                ListNode *tmp=pre->next;
                pre->next=pos->next;
                pos->next=pos->next->next;
                pre->next->next=tmp;
            }
            pre=pos;
            pos=pre->next;
        }
        return new_head->next;
    }
private:
    bool hasK(ListNode * node,int k){
        int cnt=0;
        while(node){
            ++cnt;
            if(k==cnt) return true;
            node=node->next;
        }
        return false;
    }
};
