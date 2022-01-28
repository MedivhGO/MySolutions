class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        dic = collections.defaultdict()
        for x in nums:
            if x not in dic:
                dic[x] = 1
            else:
                dic[x] += 1
        for key,  val in dic.items():
            if val == 1:
                return key
        return -1

# 哈希表

# python中, 定义一个dict使用collections.defaultdict().
# 迭代字典, 使用dict.items(), 得到所有kv.
# dict.keys() 得到所有keys.
# dict.values() 得到所有values.

# 时间复杂度 O(n)
# 空间复杂读 O(n)

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        ans = 0
        for i in range(32):
            cur_sum_bit = sum([(x >> i) & 1 for x in nums])
            if cur_sum_bit % 3 != 0:
                if i == 31:
                    ans -= (1 << i)
                else:
                    ans |= (1 << i)
        return ans

# 位运算 
# 检查32bit上出现1的次数是不是3倍数的
# 如果不是3的倍数,一定是那个唯一的数字导致的, 且那个位置为1.
# 由于python的整型移位没有溢出, 其最高位为1时, 是2^31, 而不是C/C++的-2^31
# 所以要进行特殊处理, 当i=31时, ans-= (1 << i)

# 时间复杂度 O(nlogC) C为参数数据类型的二进制位数
# 空间复杂度 O(1)
