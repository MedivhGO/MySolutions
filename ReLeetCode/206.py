class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if head == None or head.next == None:
            return head
        toLast = head.next
        newHead = self.reverseList(toLast)
        toLast.next = head
        head.next = None
        return newHead

# 递归实现版

# 时间复杂度 O(n) 需要对每个节点做反转操作,每个反转操作是常数时间.
# 空间复杂度 O(n) 一直到递归的出口case,需要保存n层调用栈.

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

# 迭代版实现
# 将每个node的next指针,指向他之前的node, 所以需要一个prev变量记录前一个node的地址, prev变量初始化为None, 
# 在循环中要首先保存,当前node的下一个node的地址,因为当前node的next指针会被prev覆盖掉
# 将当前node的next指针赋予prev
# 将prev赋予为当前node
# 将迭代用的指针赋予循环开始时得到的next指针地址
# 返回prev

# 时间复杂度 O(n)
# 空间复杂度 O(1)