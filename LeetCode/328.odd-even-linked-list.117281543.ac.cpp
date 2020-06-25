/*
 * [328] Odd Even Linked List
 *
 * https://leetcode.com/problems/odd-even-linked-list/description/
 *
 * algorithms
 * Medium (44.28%)
 * Total Accepted:    82.7K
 * Total Submissions: 186.8K
 * Testcase Example:  '[1,2,3,4,5,6,7,8]'
 *
 * Given a singly linked list, group all odd nodes together followed by the
 * even nodes. Please note here we are talking about the node number and not
 * the value in the nodes.
 * 
 * You should try to do it in place. The program should run in O(1) space
 * complexity and O(nodes) time complexity.
 * 
 * 
 * Example:
 * Given 1->2->3->4->5->NULL,
 * return 1->3->5->2->4->NULL.
 * 
 * 
 * Note:
 * The relative order inside both the even and odd groups should remain as it
 * was in the input. 
 * The first node is considered odd, the second node even and so on ...
 * 
 * 
 * Credits:Special thanks to @DjangoUnchained for adding this problem and
 * creating all test cases.
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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* oddlist = new ListNode(-1);
        ListNode* evenlist = new ListNode(-1);
        ListNode* op = oddlist;
        ListNode* ep = evenlist;
        ListNode *p = head;
        bool flag = 1;
        while (p) {
           
            if (flag) {
                op->next = p;
                op = p;
                flag = 0;
            }else {
                ep->next = p;
                ep = p;
                flag = 1;
            }
            p = p->next;
        }
        op->next = nullptr;
        ep->next = nullptr;
       
            op->next = evenlist->next;
            return oddlist->next;
        
        
        }
        
    };
