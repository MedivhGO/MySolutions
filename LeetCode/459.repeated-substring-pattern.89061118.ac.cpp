/*
 * [459] Repeated Substring Pattern
 *
 * https://leetcode.com/problems/repeated-substring-pattern/description/
 *
 * algorithms
 * Easy (38.21%)
 * Total Accepted:    44.9K
 * Total Submissions: 117.6K
 * Testcase Example:  '"abab"'
 *
 * Given a non-empty string check if it can be constructed by taking a
 * substring of it and appending multiple copies of the substring together.
 * You may assume the given string consists of lowercase English letters only
 * and its length  will not exceed 10000. 
 * 
 * Example 1:
 * 
 * Input: "abab"
 * 
 * Output: True
 * 
 * Explanation: It's the substring "ab" twice.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "aba"
 * 
 * Output: False
 * 
 * 
 * 
 * Example 3:
 * 
 * Input: "abcabcabcabc"
 * 
 * Output: True
 * 
 * Explanation: It's the substring "abc" four times. (And the substring
 * "abcabc" twice.)
 * 
 * 
 */
class Solution {
public:
    bool repeatedSubstringPattern(string str) {
       if(str.size()==1)
            return false;
        for(int i=1;i< str.size();i++) {
            string sub = str.substr(0,i);
            int sublen = i;
            size_t  p = str.find(sub);
            int count = 0;
            while(p!=std::string::npos) {
                count++;
                p = str.find(sub,p+sublen);
            }
            if(sublen*count == str.size())
                return true;
            
        }
        return false;
    }
};
