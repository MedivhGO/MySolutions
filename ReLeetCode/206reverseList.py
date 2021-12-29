# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if head == None or head.next == None:
            return head
        toLast = head.next
        newHead = self.reverseList(toLast)
        toLast.next = head
        head.next = None
        return newHead

# 时间复杂度 O(n) 需要对每个节点做反转操作,每个反转操作是常数时间.
# 空间复杂度 O(n) 一直到递归的出口case,需要保存n层调用栈.