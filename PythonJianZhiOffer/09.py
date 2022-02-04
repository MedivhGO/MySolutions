#!/usr/bin/env python
# encoding: utf-8

class CQueue:

    def __init__(self):
        self.stk = [] # 入栈
        self.stk1 = [] # 出栈

    def appendTail(self, value: int) -> None:
        self.stk.append(value)

    def deleteHead(self) -> int:
        if len(self.stk1) != 0:
            return self.stk1.pop()
        else:
            if len(self.stk) == 0:
                return -1
            self.stk1 = self.stk[::-1]
            self.stk.clear()
            return self.stk1.pop()


# 两个栈实现一个队列, 其本质是保证从一个队列里入栈, 从一个队列里出栈. 来实现FIFO.
# 要注意, 出栈的时候, 如果用于出栈的栈为空时, 要把用于入栈的栈元素,灌入到出栈的元素中.

# 时间复杂度 append时间复杂度O(1), delete的时间复杂度 O(n)
# 空间复杂度 O(n)
