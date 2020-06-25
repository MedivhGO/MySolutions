/*
 * [647] Palindromic Substrings
 *
 * https://leetcode.com/problems/palindromic-substrings/description/
 *
 * algorithms
 * Medium (55.67%)
 * Total Accepted:    26.5K
 * Total Submissions: 47.6K
 * Testcase Example:  '"abc"'
 *
 * 
 * Given a string, your task is to count how many palindromic substrings in
 * this string.
 * 
 * 
 * 
 * The substrings with different start indexes or end indexes are counted as
 * different substrings even they consist of same characters. 
 * 
 * 
 * Example 1:
 * 
 * Input: "abc"
 * Output: 3
 * Explanation: Three palindromic strings: "a", "b", "c".
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "aaa"
 * Output: 6
 * Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 * 
 * 
 * 
 * Note:
 * 
 * The input string length won't exceed 1000.
 * 
 * 
 */
class Solution {
public:
    int countSubstrings(string s) {
        //dp
        int ans = 0;
        if (s.empty()) return ans;
        int n = s.size();
        vector<vector<bool>> dp;
        dp.resize(n,vector<bool>(n,false));
        
        for (int i = n-1;i>=0;i--)
            for (int j=i;j<n;j++) {
                dp[i][j] = s[i] == s[j] && (j-i < 3 || dp[i+1][j-1]);
                if (dp[i][j]) ++ans;
            }
        return ans;
    }
};
