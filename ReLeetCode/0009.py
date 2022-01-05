class Solution:
    def isPalindrome(self, x: int) -> bool:
        raw = str(x)
        reverse = raw[::-1]
        return raw == reverse

# 先转换成字符串,然后翻转字符串,最后判断与原字符串是否相等

# 时间复杂度 O(n)
# 空间复杂度 O(n)

class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0 or (x != 0 and x % 10 == 0):
            return False
        right_part = 0
        while x > right_part:
            right_part = right_part*10 + x % 10
            x = x // 10
        return x == right_part or x == right_part // 10


# 用一个变量记录, 从x上逐个拿到的右半部的值所构成的一个新的数值,同时x不断的/10
# 当这个数大于等于这个值的时候,说明x已经遍历过半了.
# 比较x剩余部分的数值, 和right_part的数值大小, 如果x是偶数,那么如果回文的话那么x == right_part
# 如果x是奇数, 那么x == right_part // 10

# 时间复杂度 O(lgn) 因为只需要遍历一半n的10进制位数
# 空间复杂度 O(1)