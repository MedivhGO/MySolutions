class Solution:
    def hammingWeight(self, n: int) -> int:
        ans = 0
        while n != 0:
            ans += 1
            n = n & (n - 1)
        return ans

# n & (n - 1) 结果是n中最后一个1置为0

# 时间复杂度 O(k) 最坏情况下所有n的所有二进制位都为1, k位n的二进制位数
# 空间复杂度 O(1)