class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        tmp = x ^ y
        ans = 0
        while tmp:
            tmp = tmp & (tmp - 1)
            ans += 1
        return ans

# 还是公式 n & (n - 1) 将n的二进制表示的最后一个1置为0

# 时间复杂度 O(lgn)
# 空间复杂度 O(1)