class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:

        fast = slow = head
        
        while fast and fast.next != None:
            fast = fast.next.next
            slow = slow.next

            if fast == slow:
                return True

        return False
        
        
# 快慢指针

# 时间复杂度 O(n)
# 空间复杂度 O(1)