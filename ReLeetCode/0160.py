class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        len1 = 0
        len2 = 0

        cur = headA

        while cur:
            len1 += 1
            cur = cur.next
        
        cur = headB

        while cur:
            len2 += 1
            cur = cur.next
        
        longer_cur = headA if len1 > len2 else headB
        shorter_cur = headB if len1 > len2 else headA
        longer_step = len1 - len2 if len1 > len2 else len2 - len1

        while longer_step:
            longer_cur = longer_cur.next
            longer_step -= 1
        
        while shorter_cur:
            if shorter_cur == longer_cur:
                return shorter_cur
            shorter_cur = shorter_cur.next
            longer_cur = longer_cur.next
        
        return None

# 时间复杂度 O(n)
# 空间复杂度 O(1)