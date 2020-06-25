/*
 * [62] Unique Paths
 *
 * https://leetcode.com/problems/unique-paths/description/
 *
 * algorithms
 * Medium (42.17%)
 * Total Accepted:    170.4K
 * Total Submissions: 404.1K
 * Testcase Example:  '1\n2'
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below).
 * 
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 * the diagram below).
 * 
 * How many possible unique paths are there?
 * 
 * 
 * 
 * Above is a 3 x 7 grid. How many possible unique paths are there?
 * 
 * 
 * Note: m and n will be at most 100.
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
        int ans = 0;
        if (m<=0 || n <= 0) return ans;
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
   
        for (int i = 1; i<=n;i++) {
            dp[1][i] = 1;
        }
         for (int i = 1; i<=m;i++) {
            dp[i][1] = 1;
        }
        for (int i = 2; i <= m;i++)
            for(int j = 2;j <= n;j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
       return dp[m][n];
    }
};
