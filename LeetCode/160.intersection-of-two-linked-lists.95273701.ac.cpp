/*
 * [160] Intersection of Two Linked Lists
 *
 * https://leetcode.com/problems/intersection-of-two-linked-lists/description/
 *
 * algorithms
 * Easy (30.86%)
 * Total Accepted:    165.3K
 * Total Submissions: 535.8K
 * Testcase Example:  'No intersection: []\n[]'
 *
 * Write a program to find the node at which the intersection of two singly
 * linked lists begins.
 * 
 * For example, the following two linked lists: 
 * 
 * A:          a1 → a2
 * ⁠                  ↘
 * ⁠                    c1 → c2 → c3
 * ⁠                  ↗            
 * B:     b1 → b2 → b3
 * 
 * begin to intersect at node c1.
 * 
 * Notes:
 * 
 * If the two linked lists have no intersection at all, return null.
 * The linked lists must retain their original structure after the function
 * returns. 
 * You may assume there are no cycles anywhere in the entire linked structure.
 * Your code should preferably run in O(n) time and use only O(1) memory.
 * 
 * 
 * 
 * Credits:Special thanks to @stellari for adding this problem and creating all
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        
        int Alen = 0;
        int Blen = 0;
        ListNode* n = headA;
        while(n) {
            Alen++;
            n = n->next;
        }
        n = headB;
        while(n) {
            Blen++;
            n = n->next;
        }
        ListNode* headA1 = headA;
        ListNode* headB1 = headB;
        if(Alen > Blen) {
            int step = Alen - Blen;
            while(step) {
                headA1 = headA1->next;
                step--;
            }
        }
        else {
            int step = Blen - Alen;
            while(step) {
                headB1 = headB1->next;
                step--;
            }
        }
        
        while(headA1 != headB1) {
            headA1 = headA1->next;
            headB1 = headB1->next;
        }
        
        if(headA1 == NULL)
            return NULL;
        else
            return headA1;
        
    }
};
