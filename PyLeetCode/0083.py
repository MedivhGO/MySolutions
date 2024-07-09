class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if head is None or head.next is None:
            return head
        may_newhead = self.deleteDuplicates(head.next)
        if may_newhead.val == head.val:
            return may_newhead
        else:
            head.next = may_newhead
            return head

# 使用递归求解


# 时间复杂度 O(n)
# 空间复杂度 O(n)


class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if head is None or head.next is None:
            return head
        slow = head
        fast = head.next
        while fast is not None:
            if slow.val == fast.val:
                slow.next = fast.next
                fast = slow.next
            else:
                slow = slow.next
                fast = fast.next
        return head

# 双指针模拟

# 时间复杂度 O(n)
# 空间复杂度 O(1)