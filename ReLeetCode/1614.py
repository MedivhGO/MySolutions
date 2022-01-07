class Solution:
    def maxDepth(self, s: str) -> int:
        if s == None:
            return 0
        count = 0
        ans = 0
        for x in s:
            if x == '(':
                count += 1
            elif x == ')':
                ans = max(ans, count)
                count -= 1
            else:
                continue
        return ans

# 模拟, 类似括号匹配, 注意不需要使用栈, 使用一个变量计数即可.

# 时间复杂度 O(n)
# 空间复杂度 O(1)