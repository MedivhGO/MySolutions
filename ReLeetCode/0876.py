class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        if head == None or head.next == None:
            return head
        
        fast = head
        slow = head

        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next

        return slow
        
# 快慢指针

# 时间复杂度 O(n)
# 空间复杂度 O(1)