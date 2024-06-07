class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr && list2 == nullptr) {
            return nullptr;
        }
        if (list1 == nullptr && list2 != nullptr) {
            return list2;
        }
        if (list1 != nullptr && list2 == nullptr) {
            return list1;
        }
        if (list1->val < list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } 
        list2->next = mergeTwoLists(list2->next, list1);
        return list2;
    }
};

// 时间复杂度 O(n+m) 空间复杂度 O(n+n) 递归法

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr && list2 == nullptr) {
            return nullptr;
        }
        if (list1 == nullptr && list2 != nullptr) {
            return list2;
        }
        if (list1 != nullptr && list2 == nullptr) {
            return list1;
        }
        ListNode* dummy_node = new ListNode(-1);
        ListNode* pre = dummy_node;
        ListNode* p1 = list1;
        ListNode* p2 = list2;
        while (p1 != nullptr && p2 != nullptr) {
            if (p1->val < p2->val) {
                dummy_node->next = p1;
                p1 = p1->next;
            } else {
                dummy_node->next = p2;
                p2 = p2->next;
            }
            dummy_node = dummy_node->next;
        }
        if (p1 != nullptr) {
            dummy_node->next = p1;
        } else {
            dummy_node->next = p2;
        }
        return pre->next;
    }
};

// 时间复杂度 O(n+m) 空间复杂度 O(1) 迭代法