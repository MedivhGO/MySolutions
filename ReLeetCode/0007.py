class Solution:
    def reverse(self, x: int) -> int:
        is_negative = 1

        if x < 0:
            is_negative = -1
            x = -x

        reverse_num = 0
        int_max = 2147483647
        int_min = -2147483648

        while x:
            if is_negative * reverse_num * 10 > int_max or is_negative * reverse_num * 10 < int_min:
                return 0
            reverse_num = reverse_num*10 + x % 10
            x = x // 10

        reverse_num *= is_negative
        return reverse_num


# 因为题目要求不能使用int64存储中间变量, 然后进行判断是否溢出.
# 所以需要在转置过程中进行过程判断.
# 判断的思路就是: 在进行生成新的中间结果的时候, 先乘以10, 也就是扩大10倍, 看时候超过int32的边界.
# 如果扩大10倍之后超过边界了, 说明这个值转置之后的值是无法用int32表示的, 返回0
# 如果在生成新的转置值得过程中没有返回0, 那么就说明这个转置的值是不会溢出的, 返回这个转置的值.

# 时间复杂度 O(n)
# 空间复杂度 O(1)