/*
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (38.81%)
 * Total Accepted:    194.8K
 * Total Submissions: 501.9K
 * Testcase Example:  '[]'
 *
 * 
 * Given a linked list, swap every two adjacent nodes and return its head.
 * 
 * 
 * 
 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 * 
 * 
 * 
 * Your algorithm should use only constant space. You may not modify the values
 * in the list, only nodes itself can be changed.
 * 
 */
/**
 * Definition for singly-linked list.
 * struct istNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {   
        
        if (head == nullptr || head->next == nullptr)
            return head;
            
        ListNode dummy(-1);
        ListNode* ans = head->next;
        ListNode*  last = &dummy;
        while (head != nullptr && head->next != nullptr) {
             last->next =  head->next;
            
           ListNode* outer = head->next->next;
        
            last->next->next= head;
            head->next = outer;
            
            last = head;
            head = head->next;
            
          
        }
        
        
        
        
        
        return ans;
    }
};
