class MinStack:

    def __init__(self):
        self.stk = []
        self.min_stk = []


    def push(self, val: int) -> None:
        self.stk.append(val)

        if len(self.min_stk) !=0 and val <= self.min_stk[-1]:
            self.min_stk.append(val)
        elif len(self.min_stk) == 0:
            self.min_stk.append(val)


    def pop(self) -> None:
        e = self.stk.pop()
        if e == self.min_stk[-1]:
            self.min_stk.pop()


    def top(self) -> int:
        return self.stk[-1]

    def getMin(self) -> int:
        return self.min_stk[-1] if len(self.min_stk) != 0 else 0



# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()

# 维护两个栈, 其中一个栈的栈顶维持当前栈的最小值. 如果栈的出栈元素为最小栈的栈顶元素
# 最小栈的栈顶元素出栈.

# 可以使用一个栈来实现, 每次入栈时,将入栈元素和当前最小元素一起入栈.