class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        if len(num1) == 0:
            return num2

        if len(num2) == 0:
            return num1

        num1_number = []
        num2_number = []

        for e in num1:
            num1_number.append(int(e))

        for e in num2:
            num2_number.append(int(e))

        num1_number = num1_number[::-1]
        num2_number = num2_number[::-1]

        carry = 0
        ans_number = []
        common_length = min(len(num1), len(num2)) 
        for i in range(common_length):
            digital = (num1_number[i] + num2_number[i] + carry) % 10
            ans_number.append(digital)
            carry = (num1_number[i] + num2_number[i] + carry) // 10

        for i in range(common_length, len(num1)):
            digital = (num1_number[i] + carry) % 10
            ans_number.append(digital)
            carry =  (num1_number[i] + carry) // 10

        for i in range(common_length, len(num2)):
            digital = (num2_number[i] + carry) % 10
            ans_number.append(digital)
            carry =  (num2_number[i] + carry) // 10

        if carry != 0:
            ans_number.append(carry)

        ans_number = ans_number[::-1]
        ans_str = ''
        for x in ans_number:
            ans_str += str(x)

        return ans_str

# 模拟

# 时间复杂度 O(max(n, m))
# 空间复杂度 O(max(n, m))