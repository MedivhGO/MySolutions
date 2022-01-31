class Solution:
    def singleNumbers(self, nums: List[int]) -> List[int]:
        diff_xor = 0
        for x in nums:
            diff_xor ^= x
        div_num = 1
        while div_num & diff_xor == 0:
            div_num <<= 1
        ans1 = 0
        ans2 = 0
        for x in nums:
            if x & div_num == 0:
                ans1 ^= x
            else:
                ans2 ^= x
        return [ans1, ans2]

# 根据两个只出现一个次的数的某一不同的bit位进行分组.
# 首先要得到这个两个数,不同的那个bit位.
# 进行异或, 得到bit位为1的那个位置, 通过移位操作得到这个位置的mask值.
# 用这个mask值对原数组进行分组, 由于其他的数都出现了了两次, 所以分开的两组数.
# 都是一个数出现一次,其他数出现两次.
# 分别对两组进行异或.能同时得到这两个不同的值.

# 时间复杂度 O(n)
# 空间复杂度 O(1)