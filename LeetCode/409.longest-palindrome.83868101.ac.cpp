/*
 * [409] Longest Palindrome
 *
 * https://leetcode.com/problems/longest-palindrome/description/
 *
 * algorithms
 * Easy (45.67%)
 * Total Accepted:    55.8K
 * Total Submissions: 122.2K
 * Testcase Example:  '"abccccdd"'
 *
 * Given a string which consists of lowercase or uppercase letters, find the
 * length of the longest palindromes that can be built with those letters.
 * 
 * This is case sensitive, for example "Aa" is not considered a palindrome
 * here.
 * 
 * Note:
 * Assume the length of given string will not exceed 1,010.
 * 
 * 
 * Example: 
 * 
 * Input:
 * "abccccdd"
 * 
 * Output:
 * 7
 * 
 * Explanation:
 * One longest palindrome that can be built is "dccaccd", whose length is 7.
 * 
 * 
 */
class Solution {
public:
    int longestPalindrome(string s) {
        int res = 0;
        int flag = 0;
        map<char,size_t> mapping;
        for(int i=0;i<s.size();i++) {
            mapping[s[i]]++;
        }
        if(mapping.size()==1)
            return s.size();
        int count=0;
        for(auto x:mapping) {
            if(x.second%2==0) {
                res+=x.second/2;
                x.second = 0;
            }
            else {
                res+=x.second/2;
                x.second -= x.second/2*2;
                if(x.second == 1)
                    count++;
            }
        }
       if(count!=0)
            flag = 1;
        return res*2+flag;
        
    }
};
