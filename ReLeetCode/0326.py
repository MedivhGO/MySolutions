class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        return n > 0 and 1162261467 % n == 0


# int32的最大3的幂次是1162261467,所以n如果是这个数的因数就返回true
# 考虑n不为0和负数的情况

# 时间复杂度 O(1)
# 空间复杂度 O(1)