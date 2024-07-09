class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        ans = 0
        for x in nums:
            ans ^= x
        return ans


# 使用异或操作, tips 0异或任何数都是那个数本身. 也就是 0异或任何数=任何数

# 时间复杂度 O(n)
# 空间复杂度 O(1)