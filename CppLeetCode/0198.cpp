class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        int len = nums.size();
        vector<int> dp(len, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]);
        for (int i = 2; i < len; ++i) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        return dp[len-1];
    }
};


// 时间复杂度 O(n)
// 空间复杂度 O(1)

// dp[i] 表示盗窃第 i 个房屋时获得的最大收益
// 在第 i 个位置的收益，是 dp[i-1] 或者 dp[i-2] + nums[i] 中的最大值，对于 dp[1] 的收益是 max(nums[0], nums[1])
// 也就是说盗取下标为 1 家的收益为，下标为 0 家和下标为 1 家的最大值