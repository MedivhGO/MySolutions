/*
 * [142] Linked List Cycle II
 *
 * https://leetcode.com/problems/linked-list-cycle-ii/description/
 *
 * algorithms
 * Medium (30.86%)
 * Total Accepted:    133.9K
 * Total Submissions: 433.9K
 * Testcase Example:  '[]\nno cycle'
 *
 * 
 * Given a linked list, return the node where the cycle begins. If there is no
 * cycle, return null.
 * 
 * 
 * 
 * Note: Do not modify the linked list.
 * 
 * 
 * Follow up:
 * Can you solve it without using extra space?
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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return nullptr;
        if (head ->next == head) return head;
        ListNode* pre = head;
        ListNode* later = head;
        pre = pre->next;
        later = later->next;
        if (pre->next == nullptr)
            return nullptr;
        pre = pre->next;
        while (pre!=later && pre!=nullptr) {
            if (pre->next != nullptr)
                pre = pre->next->next;
            else
                return nullptr;
            later = later->next;
        }
        if (pre == nullptr)
            return nullptr;
        
        pre = head;
        while (pre!=later){
            pre = pre->next;
            later = later->next;
        }
        
        return pre;
        
    }
};
