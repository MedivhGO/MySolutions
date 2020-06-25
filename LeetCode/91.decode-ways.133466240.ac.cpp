/*
 * [91] Decode Ways
 *
 * https://leetcode.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (20.13%)
 * Total Accepted:    153.2K
 * Total Submissions: 761.2K
 * Testcase Example:  '""'
 *
 * 
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping:
 * 
 * 
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * 
 * Given an encoded message containing digits, determine the total number of
 * ways to decode it.
 * 
 * 
 * 
 * For example,
 * Given encoded message "12",
 * it could be decoded as "AB" (1 2) or "L" (12).
 * 
 * 
 * 
 * The number of ways decoding "12" is 2.
 * 
 */
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0)
            return 0;
        vector<int> dp(n, 0);
        dp[0] = 1;
        if (s[0] < '1' || s[0] > '9')
            return 0;
        for (int i = 1; i < n; i++) {
            if (s[i] != '0')
                dp[i] = dp[i - 1];
            if (s[i] == '0' && s[i - 1] > '2')
                return 0;
            if (s[i - 1] != '0' && (s[i - 1] - '0') * 10 + s[i] - '0' <= 26)
                dp[i] += (i >= 2 ? dp[i - 2] : 1);
        }
        return dp[n - 1];
        
    }
};
