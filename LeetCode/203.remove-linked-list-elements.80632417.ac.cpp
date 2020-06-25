/*
 * [203] Remove Linked List Elements
 *
 * https://leetcode.com/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (33.08%)
 * Total Accepted:    138.5K
 * Total Submissions: 418.7K
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * Remove all elements from a linked list of integers that have value val.
 * 
 * Example
 * Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6,  val = 6
 * Return: 1 --> 2 --> 3 --> 4 --> 5
 * 
 * 
 * Credits:Special thanks to @mithmatt for adding this problem and creating all
 * test cases.
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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr)
            return head;
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while(cur)
        {
            if(cur->val == val) {
                if(pre == nullptr) {
                    head = cur->next;
                    cur = cur->next;
                }
                else
                {
                    pre->next = cur->next;
                    cur = cur->next;
                }
                
            }
            else {
                pre = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};
