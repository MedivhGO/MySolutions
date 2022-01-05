class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        prev = None
        cur_head = head
        while cur_head != None:
            tmp = cur_head.next
            cur_head.next = prev
            prev = cur_head
            cur_head = tmp
        return prev
    
    def isPalindrome(self, head: ListNode) -> bool:
        if head == None or head.next == None:
            return True
        
        fast = head
        slow = head

        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
        
        raw_begin = head
        raw_end = slow
        begin = self.reverseList(slow)

        while raw_begin != raw_end:
            if raw_begin.val != begin.val:
                return False
            raw_begin = raw_begin.next
            begin = begin.next
        
        return True

# 先找到中间位置
# 然后将中间位置开始到最后的那段链表翻转
# 比较开始到中间位置的链表值,和翻转之后的半个链表值
# 如果有不相等的元素,就返回False
# 否则返回True

# 时间复杂度 O(n)
# 空间复杂度 O(1)