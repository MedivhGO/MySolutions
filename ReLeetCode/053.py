class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        num_len = len(nums)
        dp = nums
        for i in range(1, num_len):
            tmp = dp[i-1] + nums[i]
            dp[i] = max(tmp, dp[i])
        return max(dp)

# 一. 使用动态规划
# dp[n],dp数组的含义为当前i位置的最大子数组
# 因此,当计算i位置的最大子数组的时候,看i-1位置的最大子数组,也就是dp[i-1]
# dp[i-1]+nums[i],就是把当前元素也算到之前的最大子数组中
# 如果这个连续最大子数组大于,这个位置的单独的值,那么dp[i]就是dp[i-1]+nums[i]
# 否则dp[i]就是他本身,此时说明dp[i-1]是个<0的值,不可能成为一个前缀了.

# 时间复杂度O(n)
# 空间复杂度O(n)

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        ans = -99999
        cursum = 0
        for x in nums:
            cursum += x
            if cursum < 0:
                cursum = x
            cursum = max(cursum, x)
            ans = max(cursum, ans)
        return ans

# 观察一可以发现,dp[i]的状态只与dp[i-1]有关,因此可以减少空间的使用

# 时间复杂度O(n)
# 空间复杂度O(1)