class Solution:
    def countBits(self, n: int) -> List[int]:
        ans = [0] * (n + 1)
        ans[0] = 0
        for i in range(1, n + 1):
            if i % 2 == 0:
                ans[i] = ans[i // 2]
            else:
                ans[i] = ans[i - 1] + 1
        return ans


# 如果n是偶数, 那么它的二进制中1的个数和 n / 2的个数是一样的
# 如果n是奇数, 那么它的二进制中1的个数和 n - 1这个偶数中1的个数+1是一样的

# 时间复杂度 O(n)
# 空间复杂度 O(n)