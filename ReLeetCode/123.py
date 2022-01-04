class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # 该问题等价于, 不重叠的2个子数组的最大和.
        # 考虑问题, 如何得到所有2个不重叠的子数组.