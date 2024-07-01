class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        if (head->val != head->next->val) {
            head->next = deleteDuplicates(head->next);
            return head;
        } else {
            auto cur = head;
            while (cur->next && cur->val == cur->next->val) {
                cur = cur->next;
            }
            return deleteDuplicates(cur->next);
        }
    }
};

// 递归法 当 head 节点和 head->next 节点值不相等时，将 deleteDuplicates(head->next) 的结果 接到 head 上。
// 当 head 节点和 head->next 节点相等时，使用循环寻找第一个不想等的节点，返回  deleteDuplicates()
// 时间复杂度 O(n) 空间复杂度 O(n)

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* cur = head;
        while (cur) {
            while (cur->next && cur->next->val == cur->val) {
                cur = cur->next;
            }
            // pre 和 cur 之间没有重复的节点，pre 后移
            if (pre->next == cur) {
                pre = pre->next;
            } else {
                pre->next = cur->next;
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};

// 迭代法 主要是 pre 指针的移动
// 1. 当 cur 经过循环之后，如果 pre->next == cur，说明没有重复元素，pre = pre->next
// 2. 当 cur 经过循环之后，pre->next != cur 说明 cur 已经跳过了重复元素，cur 当前的位置为重复元素上
// 所以 pre->next 要指向 cur->next，
// 3. cur = cur->next，cur 跳过所有重复元素。

// 时间复杂度 O(n) 空间复杂度 O(1)