class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count = 0
        ans= -1
        n = len(nums)
        for i in range(0, n):
            if count == 0:
                ans = nums[i]
            if nums[i] == ans:
                count += 1
            else:
                count -= 1
        return ans

# 寻找出现大于n/2的元素, 投票算法.
# 摩尔投票算法
# 算法的核心思路就是
# 指定一个候选元素和计数器(计算器为0)
# 如果计数器为0, 当前元素成为候选元素
# 如果遍历的元素与候选元素相同, 计数器+1
# 如果遍历的元素与候选元素不同,
# 计数器-1, 如果计数器为0, 当前元素成为候选元素, 并将计数器置为1.
# 总之没候选元素, 计数器就是0, 有候选元素计数器就要大于等于1.

# 时间复杂度 O(n)
# 空间复杂度 O(1)

# 这个算法是在确保有众数的基础之上的.
# 如果没有众数, 那么ans的值就不是有效结果
# 需要在遍历一遍进行验证.
