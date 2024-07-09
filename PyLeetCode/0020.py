class Solution:
    def isValid(self, s: str) -> bool:
        stk = []
        for x in s:
            if x == '(' or x == '{' or x == '[':
                stk.append(x)
            elif len(stk) == 0:
                return False
            elif x == ')' and stk[-1] != '(':
                return False
            elif x == ']' and stk[-1] != '[':
                return False
            elif x == '}' and stk[-1] != '{':
                return False
            else:
                stk.pop()
        return len(stk) == 0

# 申请一个栈
# 遍历字符串
# 如果碰到左括号,进栈
# 如果碰到右括号,确认能否让栈顶元素退栈.
## 如果栈为空,不能让当前的右括号得到一个匹配的左括号,返回False
## 如果栈顶元素的左括号不匹配当前的右括号,返回False
# 退栈当前栈顶元素
# 判断当前栈是否为空,如果不为空(说明还有剩余的左括号),返回False.
# 如果为空(说明完全匹配)返回True.

# 时间复杂度O(n)
# 空间复杂度O(n)