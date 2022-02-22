class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []
        for i in range(len(nums) + 1):
            for tmp in itertools.combinations(nums, i):
                res.append(tmp)
        return res

# 使用Python提供的库函数
# itertools.combinations(iterable,r) 这个函数用来生成指定数目r的元素不重复的所有组合。

# 时间复杂度 O(n*2^n) 因为一共有2^n个子集，生成每个子集的复杂度为n，所以一共O(n*2^n)
# 空间复杂度 O(n)

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = [[]]
        for i in nums:
            res = res + [[i] + num for num in res]
        return res

# 迭代法

# 时间复杂度 O(n*2^n) 因为一共有2^n个子集，生成每个子集的复杂度为n，所以一共O(n*2^n)
# 空间复杂度 O(n)