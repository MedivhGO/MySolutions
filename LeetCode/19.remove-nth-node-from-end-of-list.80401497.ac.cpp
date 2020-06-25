/*
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (34.07%)
 * Total Accepted:    216.5K
 * Total Submissions: 635.3K
 * Testcase Example:  '[1]\n1'
 *
 * Given a linked list, remove the nth node from the end of list and return its
 * head.
 * 
 * 
 * For example,
 * 
 * 
 * ⁠  Given linked list: 1->2->3->4->5, and n = 2.
 * 
 * ⁠  After removing the second node from the end, the linked list becomes
 * 1->2->3->5.
 * 
 * 
 * 
 * Note:
 * Given n will always be valid.
 * Try to do this in one pass.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       if(head == nullptr)
        return nullptr;
       int len = 0;
       ListNode *cur = head;
       while (cur != nullptr)
       {
           len++;
           cur = cur->next;
       }
       int rm = len - n + 1;
       ListNode *pre = nullptr;
       cur = head;
       int c = 1;
       while(cur != nullptr)
       {
           if(c == rm){
               if(c == 1) {
                   return cur->next;;
               }
               else {
                    pre->next = cur->next;
                    return head;
               }
           }
           else {
               c++;
               pre = cur;
               cur = cur->next;
           }
       }
       return head;
       
    }
};
