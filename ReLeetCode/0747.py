class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        if nums is None:
            return -1
        if len(nums) == 1:
            return 0
        max_elem = float("-inf")
        secondary_elem = float("-inf")
        index = -1
        for i in range(len(nums)):
            if nums[i] > max_elem:
                index = i
                secondary_elem = max_elem
                max_elem = nums[i]
            elif nums[i] > secondary_elem:
                secondary_elem = nums[i]
        return index if max_elem >= 2 * secondary_elem else -1

# 遍历一遍求出一个数组的最大值, 次最大值
# 当x大于最大值的时候, 先把当前最大值赋值给次最大值, 然后把x赋值给最大值
# 当x小于最大值的时候, x还需要和次最大值进行比较, 如果比次最大值大, 就把x赋值给
# 次最大值.
# 题目中说最大值至少是其他值的二倍, 也就是有
# max_elem >= 2 * secondary_elem
# max_elem >= 2 * third_elem
# ......
# max_elem >= 2 * secondary_elem >= 2 * third_elem >= 2 * fourth_elem
# 可以总结出只要满足 max_elem >= 2 * secondary_elem就可以.

# 时间复杂度 O(n)
# 空间复杂度 O(1)