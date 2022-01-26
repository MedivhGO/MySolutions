class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums)
        while left < right:
            mid = int(left + (right - left) / 2)
            if nums[mid] == target:
                right = mid
            elif nums[mid] > target:
                right = mid
            elif nums[mid] < target:
                left = mid + 1
        ans = 0
        if left == len(nums) or nums[left] != target:
            return ans
        for x in nums:
            if x == nums[left]:
                ans += 1
        return ans