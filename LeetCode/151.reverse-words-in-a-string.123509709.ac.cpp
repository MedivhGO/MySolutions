/*
 * [151] Reverse Words in a String
 *
 * https://leetcode.com/problems/reverse-words-in-a-string/description/
 *
 * algorithms
 * Medium (15.69%)
 * Total Accepted:    181.9K
 * Total Submissions: 1.2M
 * Testcase Example:  '""'
 *
 * 
 * Given an input string, reverse the string word by word.
 * 
 * 
 * 
 * For example,
 * Given s = "the sky is blue",
 * return "blue is sky the".
 * 
 * 
 * 
 * Update (2015-02-12):
 * For C programmers: Try to solve it in-place in O(1) space.
 * 
 * 
 * click to show clarification.
 * 
 * Clarification:
 * 
 * 
 * 
 * What constitutes a word?
 * A sequence of non-space characters constitutes a word.
 * Could the input string contain leading or trailing spaces?
 * Yes. However, your reversed string should not contain leading or trailing
 * spaces.
 * How about multiple spaces between two words?
 * Reduce them to a single space in the reversed string.
 * 
 * 
 * 
 */
class Solution {
public:
    void reverseword(string &s,int i,int j) {
        while (i < j) {
            char t = s[i];
            s[i++]  = s[j];
            s[j--] = t;
        }
    }
    void reverseWords(string &s) {
        int i = 0,j = 0;
        int l = 0; //每一个单词的开头下标
        int len = s.length();
        int wordcount = 0;
        
        while (true) {
            while (i < len  && isspace(s[i])) i++;
            if (i == len ) break;
            if (wordcount) s[j++] = ' ';
            l = j;
            while (i < len && !isspace(s[i])) {
                s[j] = s[i];
                i++;
                j++;
            }
            reverseword(s,l,j-1);
            wordcount++;
        }
        s.resize(j);
        reverseword(s,0,j-1);
    }
};
