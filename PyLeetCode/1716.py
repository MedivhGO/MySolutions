class Solution:
    def totalMoney(self, n: int) -> int:
        total_week = n // 7
        left_day = n % 7
        sum = 0
        cycle = total_week + 1
        sum += (left_day * cycle) + left_day * (left_day - 1) / 2
        for i in range(1, total_week + 1):
            sum += 7 * i + 7 * 6 / 2
        return int(sum)

# 计算有几个完整的周,和剩余的天数, 计算每周的和,把每周的和求和再加上剩余的天数里攒的钱

# 时间复杂度 O(n)
# 空间复杂度 O(1)

class Solution:
    def totalMoney(self, n: int) -> int:
        total_week = n // 7
        left_day = n % 7
        sum = 0
        cycle = total_week + 1
        sum += (left_day * cycle) + left_day * (left_day - 1) / 2
        first_week_sum = 28
        sum += first_week_sum * total_week + total_week * (total_week -1 ) * 7 / 2
        return int(sum)

# 通过观察发现, 每个周存的钱数是一个等差数列, 因此再求周钱数的总和时,可以使用
# 等差数列的求和公式

# 时间复杂度 O(1)
# 空间复杂度 O(1)
