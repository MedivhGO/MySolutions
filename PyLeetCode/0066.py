class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        n = len(digits)
        for i in range(n-1, -1, -1):
            if digits[i] != 9:
                digits[i] += 1
                for j in range(i + 1, n):
                    digits[j] = 0
                return digits
        return [1] + [0] * n

# 从后往前遍历, 遇到不为9的值,就自增,并将其后所有元素置0

# 时间复杂度 O(n)
# 空间复杂度 O(1), 如果数组中所有的数字都是9, 那么结果就是O(n)