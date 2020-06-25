/*
 * [221] Maximal Square
 *
 * https://leetcode.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (29.87%)
 * Total Accepted:    78.2K
 * Total Submissions: 261.8K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * 
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square
 * containing only 1's and return its area.
 * 
 * 
 * For example, given the following matrix:
 * 
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * 
 * Return 4.
 * 
 * 
 * Credits:Special thanks to @Freezen for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0;
        int row = matrix.size();
        if (row == 0) return ans;
        int col = matrix[0].size();
        vector<vector<int>> dp(row,vector<int>(col,0));
        for (int i = 0;i < col;i++) {
            dp[0][i] = matrix[0][i] - '0';
            ans = max(dp[0][i],ans);
        }
        
        for (int i = 0;i < row;i++) {
            dp[i][0] = matrix[i][0] - '0';
            ans = max(dp[i][0],ans);
        }
        
        for (int i = 1; i < row ;i++) 
            for (int j = 1; j < col;j++) {
                
                if (matrix[i][j] == '1') {
                    dp[i][j] = min (dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                    ans = max(dp[i][j],ans);
                }
            }
        
         return ans*ans;
    }
       
};
