/*
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (25.16%)
 * Total Accepted:    269.2K
 * Total Submissions: 1.1M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example:
 * 
 * Input: "babad"
 * 
 * Output: "bab"
 * 
 * Note: "aba" is also a valid answer.
 * 
 * 
 * 
 * Example:
 * 
 * Input: "cbbd"
 * 
 * Output: "bb"
 * 
 * 
 */
class Solution {
public:
    string longestPalindrome(string s) {
        //dp
        if (s.empty()) return "";
        
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        int res_start = 0,res_end = 0;
        int mx = INT_MIN;
        for (int i=n-1;i>=0;i--)
            for (int j = i;j<n;j++) {
                dp[i][j] = s[i] == s[j] && (j-i < 3 || dp[i+1][j-1]);
                if (dp[i][j] && j-i > mx) {
                    mx = j-i;
                    res_start = i;
                    res_end = j;
                } 
            }
        string  ans(s.begin()+res_start,s.begin()+res_end+1);
        
        return ans;
        
    }
};
