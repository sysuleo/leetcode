/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
*/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6


 */
class Solution {
public:
    ListNode*mergeTwoLists(ListNode*l1,ListNode*l2){
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        if(l1->val < l2->val) {
            l1->next=mergeTwoLists(l1->next,l2);
            return l1;
        }
        else{
            l2->next=mergeTwoLists(l1,l2->next);
            return l2;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(!lists.size()) return NULL;
        while(lists.size()>1){
            lists.push_back(mergeTwoLists(lists[0],lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();
    }
};



//erase take time,so optimize it

class Solution {
public:
    ListNode*mergeTwoLists(ListNode*l1,ListNode*l2){
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        if(l1->val < l2->val) {
            l1->next=mergeTwoLists(l1->next,l2);  
            return l1;
        }
        else{
            l2->next=mergeTwoLists(l1,l2->next);
            return l2;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(!lists.size()) return NULL;
        int remain=lists.size();
        while(remain>1){
            for(int i=0;i<remain/2;i++){
                lists[i]=mergeTwoLists(lists[2*i],lists[2*i+1]);
            }
            if(remain%2==1){
                lists[remain/2]=lists[remain-1]; //奇数在for循环里面最后少一个merge  下标从0开始
                remain=remain/2+1;
            }
            else remain/=2;
        }
        return lists.front();
    }
};
