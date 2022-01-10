class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        n = len(nums)
        no_zero_ptr = 0
        for i in range(n):
            if nums[i] != 0:
                nums[no_zero_ptr], nums[i] = nums[i], nums[no_zero_ptr]
                no_zero_ptr += 1


# 时间复杂度 O(n)
# 空间复杂度 O(1)