class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 0:
            return 0
        if n == 1:
            return 1
        if n == 2:
            return 2

        dp = (n + 1) * [0]
        dp[0] = 0
        dp[1] = 1
        dp[2] = 2
        for i in range(3, n + 1):
            dp[i] = dp[i - 1] + dp[i - 2]
        return dp[n]


# 时间复杂度 O(n)
# 空间复杂度 O(n)


class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 0:
            return 0
        if n == 1:
            return 1
        if n == 2:
            return 2

        pprev = 1
        prev = 2
        ans = 0
        for i in range(3, n + 1):
            ans = prev + pprev
            pprev = prev
            prev = ans

        return ans

# 由第一种解法可进行空间压缩

# 时间复杂度 O(n)
# 空间复杂度 O(1)

