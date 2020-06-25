/*
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (24.55%)
 * Total Accepted:    409.6K
 * Total Submissions: 1.7M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * Examples:
 * 
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 * 
 * Given "bbbbb", the answer is "b", with the length of 1.
 * 
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the
 * answer must be a substring, "pwke" is a subsequence and not a substring.
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        if (s.empty()) return ans;
        unordered_map<char,int> m;
        for (int i = 0,j = 0; i < s.size();i++){
            if (m.find(s[i]) != m.end()) {
                j = max(j,m[s[i]]+1);
            }
            m[s[i]] = i;
            ans = max(ans,i-j+1);
        }
        return ans;
    }
};
