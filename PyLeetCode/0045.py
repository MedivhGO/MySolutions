class Solution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums)
        cur_end = 0
        this_step = 0
        ret_step = 0
        for i in range(n-1):
            if this_step >= i:
                this_step = max(this_step, i + nums[i])
                if i == cur_end:
                    ret_step += 1
                    cur_end = this_step
        return ret_step

# cur_end维护的是这一跳能达到的下标
# 如果i和cur_end相等，就需要进行一次跳跃
# 并更新cur_end

# 时间复杂度: O(n)
# 空间复杂度: O(1)