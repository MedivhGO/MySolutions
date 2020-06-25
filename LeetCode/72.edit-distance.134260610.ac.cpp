/*
 * [72] Edit Distance
 *
 * https://leetcode.com/problems/edit-distance/description/
 *
 * algorithms
 * Hard (32.27%)
 * Total Accepted:    105.3K
 * Total Submissions: 326.4K
 * Testcase Example:  '""\n""'
 *
 * 
 * Given two words word1 and word2, find the minimum number of steps required
 * to convert word1 to word2. (each operation is counted as 1 step.)
 * 
 * 
 * 
 * You have the following 3 operations permitted on a word:
 * 
 * 
 * 
 * a) Insert a character
 * b) Delete a character
 * c) Replace a character
 * 
 */
class Solution {
public:
    int minDistance(string word1, string word2) {
       int len1 = word1.size();
       int len2 = word2.size();
       vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));
       for (int i=1;i<=len1;i++)
           dp[i][0] = i;
       for (int j=1;j<=len2;j++)
           dp[0][j] = j;
        
        for (int i = 1;i <=len1;i++)
            for (int j = 1; j <=len2;j++) {
                if (word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else 
                    dp[i][j] = min(dp[i-1][j-1]+1,min(dp[i-1][j]+1,dp[i][j-1]+1));
        }
        
        return dp[len1][len2];
    
    }
};
