class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        s1 = set(nums1)
        ans = []
        for x in nums2:
            if x in s1:
                ans.append(x)
        return list(set(ans))


class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        s1 = set(nums1)
        ans = [x for x in nums2 if x in s1]
        return list(set(ans))


# 使用列表生成式

# 时间复杂度 O(n + m)
# 空间复杂度 O(n + m)