# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode()
        l1 = list1
        l2 = list2
        cur_ptr = dummy

        while l1 and l2:
            if l1.val < l2.val:
                cur_ptr.next = l1
                l1 = l1.next
                cur_ptr = cur_ptr.next
            else:
                cur_ptr.next = l2
                l2 = l2.next
                cur_ptr = cur_ptr.next
        
        while l1:
            cur_ptr.next = l1
            l1 = l1.next
            cur_ptr = cur_ptr.next
        
        while l2:
            cur_ptr.next = l2
            l2 = l2.next
            cur_ptr = cur_ptr.next

        
        return dummy.next
            
# 申请一个dummy node来简化合并操作

# 时间复杂度 O(m+n)
# 空间复杂度 O(1)