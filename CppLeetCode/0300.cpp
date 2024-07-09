class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len, 1);
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return ranges::max(dp);
    }
};

// dp[i] 的含义为以 i 为结束位置的最长递增子序列的长度
// 所以可以有 dp[i] = dp[j] + 1 (0 < j < i) nums[i] > nums[j]
// 即以 i 位置为结尾的最长递增子序列的长度是
// 从 [0,i) 区间里的所有 nums[i] 大于 nums[j] 的 dp[j] 的值 + 1
// 然后取这些值里的最大值。

// 时间复杂度 O(n)
// 空间复杂度 O(n)