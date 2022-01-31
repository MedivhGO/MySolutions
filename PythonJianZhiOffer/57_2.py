class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        left = 1
        right = 1
        ans = []
        while right < target:
            cur_range_sum = (right - left) * (left + right - 1) // 2
            if cur_range_sum < target:
                right += 1
            elif cur_range_sum > target:
                left += 1
            else:
                ans.append([i for i in range(left, right)])
                left += 1
        return ans

# 滑动窗口
# 如果窗口中的元素 > target, left左边界向右移动, 也就是当前sum减少.
# 如果窗口中的元素 < target, right右边界移动, 也就是当前sum增加.
# 如果窗口中的元素 == target, 也就是要找的连续序列. 将left向右移动继续寻找符合要求的序列.

# 时间复杂度 O(n)
# 空间复杂度 O(1)