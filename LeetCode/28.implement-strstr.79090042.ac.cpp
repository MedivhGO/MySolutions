/*
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (28.71%)
 * Total Accepted:    234.5K
 * Total Submissions: 816.9K
 * Testcase Example:  '"hello"\n"ll"'
 *
 * 
 * Implement strStr().
 * 
 * 
 * 
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 * 
 * 
 * Example 1:
 * 
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * 
 * 
 */
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0; 
        const int N = haystack.size() - needle.size()+1;//求两个序列的差值，确定循环的的次数
        for(int i=0;i<N;i++)
        {
            int j = 0;
            int k = i;
            while(haystack[k]==needle[j]&&j<needle.size()){
                j++;
                k++;
            }
            if(j == needle.size()){
                return i;
            }
                
        }
        return -1;
    }
};
