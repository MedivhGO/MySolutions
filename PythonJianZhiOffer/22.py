class Solution:
    def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
        fast = head
        while k != 0:
            fast = fast.next
            k -= 1
        slow = head
        while fast is not None:
            fast = fast.next
            slow = slow.next
        return slow

# 使用快慢指针, 可以少遍历一遍链表.

# 时间复杂度 O(n)
# 空间复杂度 O(1)


class Solution:
    ans = None
    def helper(self, head: ListNode, k: int, ans: ListNode) -> int:
        if head is None:
            return 0
        cur_no = self.helper(head.next, k, ans) + 1
        if cur_no == k:
            self.ans = head
        return cur_no
            
    def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
        self.helper(head, k, self.ans)
        return self.ans

# 使用递归实现, 定义一个辅助函数, 当递归到末尾时返回0, 之后每递归一层就+1
# 当递归函数逐层返回时,到第k层,记录node的地址.
# 当递归函数结束, 记录的node地址即为倒数第k个节点.
# helper的含义是递归访问链表..

# 时间复杂度 O(n)
# 空间复杂度 O(n)

class Solution:
    def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
        stk = []
        while head is not None:
            stk.append(head)
            head = head.next
        return stk[-k]

# 使用栈模拟

# 时间复杂度 O(n)
# 空间复杂度 O(n)