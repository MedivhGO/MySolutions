class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        cur_sum = sum(nums)
        n = len(nums)
        total_sum = n * (n + 1) / 2
        return int(total_sum - cur_sum)

# 使用数学方法, 求0 + 1 + 2 + 3 + 4 + 5 + ... n, 也就是 n * (n + 1) / 2.
# 然后减去当前nums的和, 也就是遗漏的元素.

# 时间复杂度 O(n)
# 空间复杂度 O(1)

class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        ans = 0
        n = len(nums)
        for x in  nums:
            ans ^= x
        for x in range(n + 1):
            ans ^= x
        return ans

# 因为一共 n + 1个数, nums中只有n个数, 将0..n这n+1个数添加到nums中, 那么除了没出现的那个数
# 别的数n + 1个数都出现了2次, 而有一个数只出现了一次.
# 转化为 2n + 1个数的数组中只有一个数出现了一次的问题.

# 时间复杂度 O(n)
# 空间复杂度 O(1)