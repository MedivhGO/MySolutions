class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* meet = nullptr;
        while(fast &&  fast->next ) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                meet = fast;
                break;
            }
        }
        if (meet == nullptr) {
            return nullptr;
        }
        ListNode* new_p = head;
        while(new_p != fast) {
            new_p = new_p->next;
            fast = fast->next;
        }
        return new_p;
    }
};

// 时间复杂度 O(n)
// 空间复杂度 O(1)

// 首先快慢指针找到相遇点，如下图所示为 p
/*
 *                     xxxxxxxxxxxxxxxx
 *                y xxx               xx
 *                 xx                  x
 *                 x                   x
 *         x       x                    x
 *  xxxxxxxxxxxxxxxx                    x 
 * m              nx                    x
 *                 xx                  xx
 *               z   xx                x
 *                    xx      p       xxx
 *                     xxxxxxx(x)xxxxxx
 */
// 如图可知，环的入口节点为 n
// m -> n 的长度为 x
// n -> p 的长度为 y
// p -> n 的长度为 z
// 由快慢指针的性质有如下等式
// 2 (x + y) = x + y + z + y
// 2 (x + y) 快指针走过的长度
// 化简后有 x = z
// 所以相遇点到环入口节点的距离与从头节点开始到入口节点的距离是相同的