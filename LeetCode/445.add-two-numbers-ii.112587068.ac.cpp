/*
 * [445] Add Two Numbers II
 *
 * https://leetcode.com/problems/add-two-numbers-ii/description/
 *
 * algorithms
 * Medium (45.99%)
 * Total Accepted:    39.7K
 * Total Submissions: 86.4K
 * Testcase Example:  '[7,2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The most significant digit comes first and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Follow up:
 * What if you cannot modify the input lists? In other words, reversing the
 * lists is not allowed.
 * 
 * 
 * 
 * Example:
 * 
 * Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 8 -> 0 -> 7
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       if (l1 == nullptr || l2 == nullptr) {
           return l1 == nullptr ? l2 : l1;
       }
       //得到两个链表的长度
       ListNode* p1 = l1;
       ListNode* p2 = l2;
       int len1 = 0,len2 = 0;
       vector<int> elem1,elem2;
       while (p1) {
           len1++;
           elem1.push_back(p1->val);
           p1 = p1->next;
       }
       while (p2) {
           len2++;
           elem2.push_back(p2->val);
           p2 = p2->next;
       }
       stack<int> res_stk;
       int carry=0;
       int i = elem1.size()-1,j = elem2.size()-1;
       for (;i>=0&&j>=0;i--,j--) {
           int mid_res = elem1[i] + elem2[j] +carry;
           int full = mid_res%10;
           carry = mid_res/10;
           res_stk.push(full);
       }
       if (i < 0) {
          while(j>=0) {
              int mid_res = elem2[j]+carry;
              int full = mid_res%10;
              carry = mid_res/10;
              res_stk.push(full);
              j--;
          }
       }
       if (j < 0)  {
           while(i>=0) {
              int mid_res = elem1[i]+carry;
              int full = mid_res%10;
              carry = mid_res/10;
              res_stk.push(full);
              i--;
          }
       }
       if (carry != 0) 
           res_stk.push(carry);
       cout << res_stk.size() << endl;
       ListNode* res_p = new ListNode(-1);
       ListNode* p = res_p;
       while(!res_stk.empty()) {
           
           ListNode *t = new ListNode(res_stk.top());
           res_stk.pop();
           t->next == nullptr;
           res_p ->next = t;
           res_p = t;
       }
       return p->next;
       
      
      
       
    }
};
