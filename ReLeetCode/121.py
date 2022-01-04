class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        diff_prices = []
        for i in range(1, n):
            diff_prices.append(prices[i] - prices[i-1])
        ans_max = -99999
        cur_sum = 0
        for x in diff_prices:
            cur_sum += x
            cur_sum = max(cur_sum, x)
            ans_max = max(cur_sum, ans_max)
        return 0 if ans_max <= 0  else ans_max

# 通过观察发现
# 由于没有限制交易次数, 发现第一天买第二天卖,然后一直如此交易到第n天
# 与第一天买第n天卖得到的利润是相同的.
# 所以这个问题可以转化为,先求每天交易的差数组,然后转换为连续最大子数组和的问题

# 时间复杂度 O(n)
# 空间复杂度 O(n)


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        ans_max = -99999
        cur_sum = 0
        for i in range(1, n):
            x = prices[i] - prices[i - 1]
            cur_sum += x
            cur_sum = max(cur_sum, x)
            ans_max = max(cur_sum, ans_max)
        return 0 if ans_max <= 0  else ans_max

# 方法一可以进行化简

# 时间复杂度 O(n)
# 空间复杂度 O(1)