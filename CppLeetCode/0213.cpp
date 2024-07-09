class Solution {
public:
    int robRange(vector<int>& nums, int start, int end) {
        vector<int> dp(nums.size(), 0);
        dp[start] = nums[start];
        dp[start+1] = max(nums[start], nums[start+1]);
        for (int i = start+2; i <= end; ++i) {
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        }
        return std::ranges::max(dp);
    }

    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) {
            return nums[0];
        }
        if (len == 2) {
            return max(nums[0], nums[1]);
        }
        int plan1 = robRange(nums, 0, len-2);
        int plan2 = robRange(nums, 1, len-1);
        return max(plan1, plan2);
    }
};

// 时间复杂度 O(n)
// 空间复杂度 O(n) 可以通过状态压缩将空间复杂度下降到 O(1)

// 当房屋的数目超过 3 时，就需要考虑第 1 间房屋和最后 1 间房屋不能同时偷窃的问题
// 因此，可以通过确定偷窃房屋的下标范围来解决这个问题，我们有了两个偷窃序列
// [0, len-2] , [1, len-1] 下标序列
// 对上述两个下标序列中的值运用 打家劫舍1 中的算法，最后两个结果的最大值即可。