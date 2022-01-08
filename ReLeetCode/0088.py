class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        dest_ptr = m + n - 1
        l1_ptr = m - 1
        l2_ptr = n - 1

        while l1_ptr >= 0 and l2_ptr >= 0:
            if nums1[l1_ptr] >=  nums2[l2_ptr]:
                nums1[dest_ptr] = nums1[l1_ptr]
                l1_ptr -= 1
            else:
                nums1[dest_ptr] = nums2[l2_ptr]
                l2_ptr -= 1
            dest_ptr -= 1
        
        while l2_ptr >= 0:
            nums1[dest_ptr] = nums2[l2_ptr]
            l2_ptr -= 1
            dest_ptr -= 1

# 双指针, 从后往前合并, 仅需要考虑nums2没走到头, nums1走到头的情况.

# 时间复杂度 O(m + n)
# 空间复杂度 O(1)