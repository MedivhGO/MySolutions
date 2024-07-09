class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        front = 0
        tail = len(s) - 1
        while front < tail:
            s[front], s[tail] = s[tail], s[front]
            front += 1
            tail -= 1
        return s

# 双指针, 注意循环结束条件

# 时间复杂度 O(n)
# 空间复杂度 O(1)