/*
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (33.25%)
 * Total Accepted:    137.1K
 * Total Submissions: 412.2K
 * Testcase Example:  '[]'
 *
 * Given a singly linked list, determine if it is a palindrome.
 * 
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome(ListNode* head) {
        stack<int> stk;
        ListNode *cur = head;
        int len = 0;
        while(cur!= nullptr) {
            len++;
            cur = cur->next;
        }
        if(len==0||len==1)
            return true;
        cur = head;
        for(int i=1;i<=len;i++)
        {
            if(len%2==0){
                if(i<=len/2) {
                    stk.push(cur->val);
                    cur = cur->next;
                } else {
                    if(stk.top()!= (cur->val))
                        return false;
                    else{
                        cur = cur->next;
                        stk.pop();
                    }
                }
            }
            else {
                if(i<=len/2) {
                    stk.push(cur->val);
                    cur = cur->next;
                }
                if(i==len/2+1){
                    cur = cur->next;
                }
                if(i>=len/2+2) {
                    if(stk.top()!= (cur->val))
                        return false;
                    else{
                        cur = cur->next;
                        stk.pop();
                    }
                }
                
            }
    }
        return true;
}
};
