class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if n == 0:
            return False
        n = n & (n - 1)
        return n == 0


# 一个数是不是2的幂次,说明这个n的二进制表示里只有一个0, n & (n - 1) 消去二进制串中的一个1.
# 如果之后这个数为0,那么就是2的幂次.

# 时间复杂度 O(1)
# 空间复杂度 O(1)