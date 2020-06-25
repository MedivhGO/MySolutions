/*
 * [92] Reverse Linked List II
 *
 * https://leetcode.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (31.11%)
 * Total Accepted:    127.7K
 * Total Submissions: 410.4K
 * Testcase Example:  '[5]\n1\n1'
 *
 * 
 * Reverse a linked list from position m to n. Do it in-place and in
 * one-pass.
 * 
 * 
 * 
 * For example:
 * Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 * 
 * 
 * return 1->4->3->2->5->NULL.
 * 
 * 
 * Note:
 * Given m, n satisfy the following condition:
 * 1 ≤ m ≤ n ≤ length of list.
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==n) return head;
        n-=m;
        ListNode dumb(0);
        dumb.next = head;
        ListNode* pre = &dumb;
        while (--m) {
            pre = pre->next;
        }//第m-1个元素
        ListNode* pstart = pre->next; //第m个元素
        while(n--) {
            ListNode *p=pstart->next;
            pstart->next=p->next;
            p->next=pre->next;
            pre->next=p;
        }
        
        return dumb.next;
    }
};
