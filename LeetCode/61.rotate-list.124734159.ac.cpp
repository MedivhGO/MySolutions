/*
 * [61] Rotate List
 *
 * https://leetcode.com/problems/rotate-list/description/
 *
 * algorithms
 * Medium (24.39%)
 * Total Accepted:    126.2K
 * Total Submissions: 517.5K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a list, rotate the list to the right by k places, where k is
 * non-negative.
 * 
 * 
 * 
 * Example:
 * 
 * Given 1->2->3->4->5->NULL and k = 2,
 * 
 * return 4->5->1->2->3->NULL.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0) return head;
        int len = 0;
        ListNode* p = head;
        while (p) {
            len++;
            p = p->next;
        }
        int pos = k % len;
        pos = len - pos;
        ListNode* newHead = nullptr;
        ListNode* pre = nullptr;
        p = head;
        int count = 0;
        while (count < pos) {
            count++;
            pre = p;
            p = p->next;
        }
        pre->next = nullptr;
        if (p == nullptr)
            return head;
        newHead = p;
        while (p->next!=nullptr) {
            p = p->next;
        }
        p->next = head;
        
        return newHead;
        
    }
};
