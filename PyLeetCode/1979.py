class Solution:
    def findGCD(self, nums: List[int]) -> int:
        def getGCD(a, b):
            if a < b :
                a, b = b, a
            gcd = (a if b == 0 else getGCD(b, a % b))
            return gcd
        max_num = max(nums)
        min_num = min(nums)
        return getGCD(max_num, min_num)

# 先写求最大公约数 (递归版)

# 时间复杂度 O(n + lg(max_num))
# 空间复杂度 O(lg(max_num))

class Solution:
    def findGCD(self, nums: List[int]) -> int:
        def getGCD(a, b):
            if a < b:
                a, b = b, a
            while b != 0:
                a, b = b, a % b
            return a
        max_num = max(nums)
        min_num = min(nums)
        return getGCD(max_num, min_num)

# 先写求最大公约数 (迭代版)

# 时间复杂度 O(n + lg(max_num))
# 空间复杂度 O(1)

# 求最大公约数用欧几里得的辗转相除
# gcd(a, b) = gcd(b, a % b), b为 a, b中较小的那个数.