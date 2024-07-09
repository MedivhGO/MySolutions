class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1
        while left <= right:
            mid = int(left + (right - left) / 2)
            if nums[mid] == target:
                return mid
            elif nums[mid] > target:
                right = mid - 1
            else:
                left = mid + 1
        return -1

# 先找中间元素, 如果nums[mid] == target 直接返回.
# 如果中间元素 > target, 右边界变为mid - 1.
# 否则左边界left = mid + 1.
# 如果没找到, 就返回-1.

# 时间复杂度 O(lgn)
# 空间复杂度 O(1)

# 上述解法有问题
# 考虑 nums = [1,2,2,2,3], target = 2 这种case, 返回2.
# 但是不能找到target的左侧边界, 即索引1, 或者右侧边界, 即索引2


# 寻找左侧边界的二分查找

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums)
        while left < right:
            mid = int(left + (right - left) / 2)
            if nums[mid] >= target: # 等号一定是跟在想要继续搜索的那部分的判断条件上.
                right = mid
            else:
                left = mid + 1
        if left == len(nums): # left指的是小于target值的个数, 如果left值为nums.lenth, 说明
            return -1         # target比所有的nums中的值都大, 返回 -1
        return left if nums[left] == target else -1 # left的值的在[0, nums.length)之间, 需要继续判断,left是不是边界值.

# 时间复杂度 O(lgn)
# 空间复杂度 O(1)



# 寻找右侧边界的二分查找

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums)
        while left < right:
            mid = int(left + (right - left) / 2)
            if nums[mid] < target: # 等号一定是跟在想要继续搜索的那部分的判断条件上.
                left = mid + 1
            elif nums[mid] > target:
                right = mid
            elif nums[mid] < target:
                left = mid + 1
        return left - 1 if nums[left - 1] else -1 # 因为一直在找右边界也就是往right的方向收敛, 最后left = right
                                                  # right没有指向实际的值. 所以使用left - 1进行判断

# 时间复杂度 O(lgn)
# 空间复杂度 O(1)


# 总结, 对于寻找左右侧边界的写法, 就是要在找到一个target后, 继续缩小搜索,左右两个区域的搜索范围.


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        right = len(nums) - 1
        return self.helper(nums, 0, right, target)

    def helper(self, nums: List[int], left: int, right: int, target: int)-> int:
        if left > right:
            return -1
        mid = int(left + (right - left) / 2)
        if nums[mid] == target:
            return mid
        elif nums[mid] > target:
            return self.helper(nums, left, mid - 1, target)
        else:
            return self.helper(nums, mid + 1, right, target)

# 递归版, 需要重新定义一个函数, 来共享对nums的操作.

# 时间复杂度 O(lgn)
# 空间复杂度 O(lgn)