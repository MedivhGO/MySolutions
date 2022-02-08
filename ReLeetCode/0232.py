class MyQueue:

    def __init__(self):
        self.input = []
        self.output = []

    def __transfer(self):
        if len(self.output) == 0:
            if len(self.input) != 0:
                for i in range(len(self.input) - 1, -1, -1): # 需要迭代, 避免浅拷贝
                    self.output.append(self.input[i])
                self.input.clear()

    def push(self, x: int) -> None:
        self.input.append(x)


    def pop(self) -> int:
        self.__transfer()
        if len(self.output) == 0:
            return -1
        return self.output.pop()


    def peek(self) -> int:
        self.__transfer()
        if len(self.output) == 0:
            return -1
        return self.output[-1]
        


    def empty(self) -> bool:
        return len(self.input) == 0 and len(self.output) == 0

# 时间复杂度 push和empty的时间复杂度 O(1). 对于每个元素, 入栈和出栈次数为2次
# 因为O(n)的操作会发生在某一个元素的pop或者peek上, 其他操作均为O(1), 所以均摊复杂度为 O(1).
# 空间复杂度 O(n)