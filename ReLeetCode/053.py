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
            cursum = max(cursum, x)
            ans = max(cursum, ans)
        return ans

# 观察一可以发现,dp[i]的状态只与dp[i-1]有关,因此可以减少空间的使用

# 时间复杂度O(n)
# 空间复杂度O(1)


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return nums[0]
        else:
            max_left = self.maxSubArray(nums[0:n//2])
            max_right = self.maxSubArray(nums[n//2:n])

        #最长子数组从中间穿过
        max_l = nums[n // 2 - 1]
        tmp = 0
        for i in range(n // 2 - 1, -1, -1):
            tmp += nums[i]
            max_l = max(tmp, max_l)

        max_r = nums[n // 2]
        tmp = 0
        for i in range(n // 2, n):
            tmp += nums[i]
            max_r = max(tmp, max_r)

        return max(max_right, max_left, max_l + max_r)

# 使用分治,递归的方法

# case1. 最大连续子数组在左半部分
# case2. 最大连续子数组在右半部分
# case3. 最大连续子数组从中间穿过
# 结果就是这三个case中最大的情况
# 当处理case3时, 先确定中间的两个元素,然后分别从中间向两边,求得连续的元素和的最大值.
# 也就是,逐渐累加左右部分各个元素之后的一个最大值,因为不用知道确切的是中间到两边具体的
# 范围,所以累加就可以解决问题.

# 时间复杂度O(nlgn) T(n) = 2T(n/2) + O(n).
# 空间复杂度O(lgn) 因为两个递归调用有2lg(n/2)深的调用栈.

