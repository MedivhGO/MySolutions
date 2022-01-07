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

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if list1 == None and list2 == None:
            return None
        if list1 != None and list2 == None:
            return list1
        if list2 != None and list1 == None:
            return list2
        if list1.val <= list2.val:
            list1.next = self.mergeTwoLists(list1.next, list2)
            return list1
        else:
            list2.next = self.mergeTwoLists(list1, list2.next)
            return list2


# 使用递归来实现, 递归的出口为两个list都为空,或者其中一个为空
# 如果list1.val <= list2.val, 说明list1为合并后链表的第一个节点, list1.next为list1.next和list2合并之后的结果
# 最后返回list1
# 如果list1.val > list2.val, 与前面的相反
# 最后返回list2

# 时间复杂度 O(m + n)
# 空间复杂度 O(m + n)