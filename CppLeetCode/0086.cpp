class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* dummy_smaller = new ListNode(-1);
        ListNode* dummy_bigger = new ListNode(-1);
        ListNode* p = head;
        ListNode* sp = dummy_smaller;
        ListNode* bp = dummy_bigger;
        while (p) {
            if (p->val < x) {
                sp->next = p;
                sp = sp->next;
            } else {
                bp->next = p;
                bp = bp->next;
            }
            p = p->next;
        }
        sp->next = dummy_bigger->next;
        bp->next = nullptr;
        return dummy_smaller->next;
    }
};

// 1. 定义两个哑节点来分别代表小于 x 和 大于 x 值的值链表
// 然后迭代原始链表
// 2. small 链表下一个节点是 big 链表的节点开始指针
// 3. big 链表迭代指针的下一个节点是空