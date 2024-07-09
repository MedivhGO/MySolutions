class Solution:
    def countHelper(self, head: ListNode, n: int) -> int:
        if head is None:
            return 0
        cur_count = self.countHelper(head.next, n) + 1            
        if cur_count  == n + 1:
            head.next = head.next.next
        return cur_count

    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        dummy = ListNode()
        dummy.next = head
        self.countHelper(dummy, n)
        return dummy.next

# 递归

# 时间复杂度 O(n)
# 空间复杂度 O(n)

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        dummy = ListNode()
        dummy.next = head
        slow = dummy
        fast = head
        while n != 0:
            fast = fast.next
            n -= 1
        while fast is not None:
            fast = fast.next
            slow = slow.next
        slow.next = slow.next.next
        return dummy.next

# 双指针

# 时间复杂度 O(n)
# 空间复杂度 O(1)