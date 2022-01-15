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