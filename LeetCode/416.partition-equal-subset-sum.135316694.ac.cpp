class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.empty()) return false;
        int len = nums.size();
        
        int sum = 0;
        for (auto x : nums) {
            sum+=x;
        }
        if ((sum&1) == 1) return false;
        sum/=2;
        vector<vector<bool>> dp(len+1,vector<bool>(sum+1,false));
        dp[0][0] = true;
        for (int i = 1;i <= len;i++) {
            dp[i][0] = true;
        }
        for (int j = 1; j <= sum;j++) {
            dp[0][j] = false;
        }
        for (int i = 1; i <= len;i++) 
            for (int j = 1; j <= sum;j++) {
               dp[i][j] = dp[i-1][j] ;//不选择第i个元素
               if (j >= nums[i-1]) {
                   dp[i][j] = (dp[i][j] || dp[i-1][j-nums[i-1]]);
               }
            }
        
        return dp[len][sum];
        
        
        
    }
};
