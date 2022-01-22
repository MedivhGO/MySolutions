class Solution:
    def xorOperation(self, n: int, start: int) -> int:
        ans = 0
        for i in range(n):
            ans ^= start + 2*i
        return ans;

# 按照题目描述求值

# 时间复杂度 O(n)
# 空间复杂度 O(1)

class Solution:
    def helper(self, n: int) -> int:
        if n % 4 == 0:
            return n
        elif (n - 1) % 4 == 0:
            return 1
        elif (n - 2) % 4 == 0:
            return n + 1
        else:
            return 0

    def xorOperation(self, n: int, start: int) -> int:
        part2 = start & 1 & n
        start = start >> 1
        part1 = self.helper(start - 1) ^ self.helper(start + n - 1)
        return part1 << 1 | part2

# 对于全是偶数的数组的, 我们先不考虑其最后一位的情况.
# 也就是[2, 4 6, 8, 10] 还是 [2, 4 6, 8, 10] 
# 对于全是奇数的数组的, 我们先不考虑其最后一位的情况.
# 比如 [3, 5, 7, 9, 11], 就变成了 [2, 4, 6, 8, 10], 然后我们把最后所有值都除2
# 变成了 [1, 2, 3, 4, 5], 现在我们来求[1, 2, 3, 4, 5]的所有值的异或
# 也就是求 1^2^3^4^....
# 总结数学规律
# 如果 n=4k sumxor(n) = n
# 如果 n=4k + 1 sumxor(n) = 1
# 如果 n = 4k + 2 sumxor(n) = n + 1
# 如果 n = 4k + 3 sumxor(n) = 0
# 对于给定start和n 也就是求 s ^ (s + 1) ^ (s + 2) ....
# 可以转化为求 t = sumxor(start-1) ^ sumxor(start + n -1)
# 得到这个t, 我们再把它*2, 然后 | 上末尾的e, 也就是结果
# 末尾的e, 如果start是偶数, 那么末尾e就是0
# 末尾的e, 如果start是奇数, 如果就要看n, n如果是奇数e=1, n如果是偶数 e = 0
# 总结一下, 也就是start,n末尾都为1时, e才为1
# 所以末尾的e值, e = start & n & 1

# 时间复杂度 O(1)
# 空间复杂度 O(1)