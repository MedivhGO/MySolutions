class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) {
            return head;
        }
        right = right - left;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;
        while (--left) {
            pre = pre->next;
        }
        ListNode* start = pre->next;
        while (right--) {
            ListNode* start_next = start->next;
            start->next = start_next->next;
            start_next -> next = pre->next;
            pre->next = start_next;
        }
        return dummy->next;
    }
};

// 定义哑节点和 pre 指针，pre 指针指向 left 前一个节点，
// 设置 cur 指针，cur_next 指针分别指向 left 和 left 的下一个节点
// 按照如下步骤进行翻转字符串
// pre -> cur -> cur_next -> other
// pre -> cur -> other
// cur_next -> cur -> other
// pre -> cur_next -> cur -> other
// 顺序不可改变

// 时间复杂度 O(n)
// 空间复杂度 O(1)