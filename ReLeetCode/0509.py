class Solution:
    def fib(self, n: int) -> int:
        if n == 1 or n == 2:
            return 1
        prev = 1
        pprev = 1
        ans = 0
        for i in range(3, n+1):
            ans = prev + pprev
            pprev = prev
            prev = ans
        return ans

# 使用递推的动态规划

# 时间复杂度 O(n)
# 空间复杂度 O(1)