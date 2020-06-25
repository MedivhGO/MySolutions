/*
 * [138] Copy List with Random Pointer
 *
 * https://leetcode.com/problems/copy-list-with-random-pointer/description/
 *
 * algorithms
 * Medium (26.00%)
 * Total Accepted:    139.7K
 * Total Submissions: 537.2K
 * Testcase Example:  '{}'
 *
 * 
 * A linked list is given such that each node contains an additional random
 * pointer which could point to any node in the list or null.
 * 
 * 
 * 
 * Return a deep copy of the list.
 * 
 */
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == nullptr) return nullptr;
        RandomListNode* newhead,*l1,*l2;
        l1 = head;
        //每个节点后面追加一个他本身的节点
        while (l1!=nullptr) {
            l2 = new RandomListNode(l1->label);
            l2->next = l1->next;
            l1->next = l2;
            
            l1 = l1->next->next;
        }
        //保存复制后的节点作为新的头节点
        newhead = head->next;
        //为复制出来的节点的random域赋值
        l1 =  head;
        while (l1 != nullptr) {
            l2 = l1->random;
            if (l2 !=nullptr)
                l1->next->random = l2->next;
            l1 = l1->next->next;
        }
       
        //将链表分开
        
        l1 = head;
        while (l1!=nullptr) {
            l2 = l1->next;
            l1->next = l2->next;
            if (l2->next != nullptr) l2->next = l2->next->next;
            l1 = l1->next;
        }
        
        return newhead;
    }
};
