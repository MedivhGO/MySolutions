class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for(int j = 0; j < coins.size(); ++j) {
                if (i - coins[j] >= 0) {
                    dp[i] = min(dp[i], dp[i-coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

// 设置 dp 数组表示要凑齐 i 个面额数值需要的最小硬币数 dp[i]。
// dp 的初始值设置为 amount+1 是指凑每个 amount 的需要的最多硬币数的上限值为 amount+1
// i-coins[j] 是指凑 i 数额时，使用了一枚 coins[j] 硬币，所以需要的硬币数为 dp[i-coins[j]] 枚硬币 + 1
// 状态转移方程为 dp[i] = min(dp[i], dp[i-coins[j]]+1)
// 当 dp[amount] > amount 也就是没有比上限更小的方案来凑出 amount 枚硬币，所以返回 -1

// 时间复杂度 O(n)
// 空间复杂度 O(n)