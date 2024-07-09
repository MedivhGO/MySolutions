class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        n = len(nums)
        unique_ptr = 1
        for i in range(n - 1):
            if nums[i] != nums[i + 1]:
                nums[unique_ptr] = nums[i + 1]
                unique_ptr += 1
        return unique_ptr


# 使用双指针, 维护一个符合结果数组

# 时间复杂度 O(n)
# 空间复杂度 O(1)