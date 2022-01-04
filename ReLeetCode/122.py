class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        ans = 0
        for i in range (1, len(prices)):
            x = prices[i] - prices[i - 1]
            if x > 0:
                ans += x
        return ans

# 由于可以多次交易,所以可以转换为最大公共子序列和问题,也就是求diff数组中大于0的数的和.

# 时间复杂度 O(n)
# 空间复杂度 O(1)