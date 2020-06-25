/*
 * [387] First Unique Character in a String
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (47.21%)
 * Total Accepted:    92.4K
 * Total Submissions: 195.6K
 * Testcase Example:  '"leetcode"'
 *
 * 
 * Given a string, find the first non-repeating character in it and return it's
 * index. If it doesn't exist, return -1.
 * 
 * Examples:
 * 
 * s = "leetcode"
 * return 0.
 * 
 * s = "loveleetcode",
 * return 2.
 * 
 * 
 * 
 * 
 * Note: You may assume the string contain only lowercase letters.
 * 
 */
class Solution {
public:
    int firstUniqChar(string s) {
        int ans = -1;
        int len = s.size();
        if (len == 0) return -1;
        unordered_map<char,size_t> m;
        for (int i = 0;i < len;i++) {
           m[s[i]]++;
        }
        for(int i = 0;i<len;i++) {
            if(m[s[i]] == 1 ) {
                ans = i;
                break;
            }       
        }
        return ans;
    }
};
