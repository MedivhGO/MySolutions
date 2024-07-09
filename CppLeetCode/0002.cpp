class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr && l2 == nullptr) {
            return nullptr;
        }
        if (l1 == nullptr && l2 != nullptr) {
            return l2;
        }
        if (l1 != nullptr && l2 == nullptr) {
            return l1;
        }
        ListNode* res1 = l1;
        ListNode* res2 = l2;
        int carry = 0;
        while (l1 && l2) {
            int cur_val = l1->val + l2->val + carry;
            int set_val = (cur_val) % 10;
            carry = cur_val / 10;
            l1->val = set_val;
            l2->val = set_val;
            l1 = l1->next;
            l2 = l2->next;
        }

        ListNode* res = (l1 == nullptr) ? res2 : res1;

        while (l1) {
            int cur_val = l1->val + carry;
            int set_val = (cur_val) % 10;
            carry = cur_val / 10;
            l1->val = set_val;
            l1 = l1->next;
        }
        while (l2) {
            int cur_val = l2->val + carry;
            int set_val = (cur_val) % 10;
            carry = cur_val / 10;
            l2->val = set_val;
            l2 = l2->next;
        }
        
        if (carry != 0) {
            ListNode* end = res;
            while (end->next != nullptr) {
                end = end->next;
            }
            ListNode* new_node = new ListNode(carry);
            end->next = new_node;
            new_node->next = nullptr;
        }
        return res;
    }
};

// 时间复杂度 O(n)
// 空间复杂度 O(1)

// 模拟加法过程即可