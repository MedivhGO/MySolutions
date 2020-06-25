/*
 * [206] Reverse Linked List
 *
 * https://leetcode.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (46.35%)
 * Total Accepted:    297.4K
 * Total Submissions: 641.7K
 * Testcase Example:  '[]'
 *
 * Reverse a singly linked list.
 * 
 * click to show more hints.
 * 
 * Hint:
 * A linked list can be reversed either iteratively or recursively. Could you
 * implement both?
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
    ListNode* reverseList(ListNode* head) {
        std::list<int> ilst;
        ListNode* p = head;
        while(p) {
            ilst.push_back(p->val);
            p = p->next;
        }
        p = head;
        ilst.reverse();
        for (auto x : ilst) {
            p->val = x;
            p = p->next;
        }
        return head;
    }
};
