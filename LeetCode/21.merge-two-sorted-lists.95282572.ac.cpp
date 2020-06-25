/*
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (39.76%)
 * Total Accepted:    294.2K
 * Total Submissions: 740K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 * 
 * 
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* res=nullptr;
        if(!l1)
            return res = l2;
        else if(!l2)
            return res = l1;
        
        if(l1->val < l2->val) {
            res = l1;
            l1 = l1->next;
        }
        else {
            res = l2;
            l2 = l2 -> next;
        }
       
        ListNode* t  = res;
        while(l1 && l2) {
            if(l1->val < l2 -> val) {
                t->next = l1;
                t = l1;
                l1 = l1->next;
            }
            else {
                t ->next = l2;
                t = l2;
                l2 = l2 ->next;
            }
        }
        if(!l1)
            t->next = l2;
        else 
            t->next = l1;
        
        return res;
        
}
    
    
};
