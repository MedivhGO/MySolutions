/*
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (28.22%)
 * Total Accepted:    412K
 * Total Submissions: 1.5M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * 
 * Example
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
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
    ListNode* addTwoNumbers(ListNode* p1, ListNode* p2) {
        if (p1 == nullptr && p2 == nullptr)
            return nullptr;
        int carry = 0;
        int val = 0;
        ListNode* ans = new ListNode(-11);
        ListNode* res = ans;
        while (p1 && p2) {
            int tmp = p1->val+p2->val+carry;
           
            val = tmp%10;
           
            carry = tmp/10;
            
            ListNode* sub = new ListNode(val);
            ans->next = sub;
            ans = sub;
            
            p1 = p1->next;
            p2 = p2->next;
        }
        
        while (p1) {
            int tmp = p1->val+carry;
            val = tmp%10;
            carry = tmp/10;
            ListNode* sub = new ListNode(val);
            ans->next = sub;
            ans = sub;
            
            p1 = p1->next;
        }
        
        while (p2) {
             int tmp = p2->val+carry;
            val = tmp%10;
            carry = tmp/10;
            ListNode* sub = new ListNode(val);
            ans->next = sub;
            ans = sub;
            
            p2 = p2->next;
        }
        
        if (carry == 1) {
            ListNode* t = new ListNode(1);
            
            ans->next = t;
        }
        
        return res->next;
   
        
    }
};
