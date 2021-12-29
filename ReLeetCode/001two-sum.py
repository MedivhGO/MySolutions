class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dict_map = {}
        ans = []
        for index in range(len(nums)):
            key, value = nums[index], index
            if (target - key) in dict_map.keys() and dict_map[target - key] < value: # 有和为target的值,且这个值的下标小于value,也就是当前值的下标
                ans.append(value)
                ans.append(dict_map[target-key])
            dict_map[nums[index]] = index
        return ans

# 这里我们一边遍历数组,一边建立map,用下标高的元素,来确定下标低的元素.
# 这样来处理[3,3] 6这样的case.
# 以免遍历到第二个3的时候,使用map会覆盖掉第一个3的下标值.

# 时间复杂度O(n)
# 空间复杂度O(n)