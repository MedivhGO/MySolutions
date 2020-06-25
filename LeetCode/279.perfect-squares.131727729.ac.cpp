/*
 * [279] Perfect Squares
 *
 * https://leetcode.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (37.64%)
 * Total Accepted:    96.9K
 * Total Submissions: 257.3K
 * Testcase Example:  '1'
 *
 * 
 * Given a positive integer n, find the least number of perfect square numbers
 * (for example, 1, 4, 9, 16, ...) which sum to n.
 * 
 * 
 * 
 * For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13,
 * return 2 because 13 = 4 + 9.
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
class Solution {
public:
    int numSquares(int n) {
        int ans = 0;
        if (n <= 0) return ans;
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;
        dp[1]= 1;
        for (int i = 1; i <=n ;i++) {
            for (int j = 1;j*j<=i;j++){
                dp[i] = min(dp[i],dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
};
