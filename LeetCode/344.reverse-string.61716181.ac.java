/*
 * [344] Reverse String
 *
 * https://leetcode.com/problems/reverse-string/description/
 *
 * algorithms
 * Easy (59.81%)
 * Total Accepted:    204.2K
 * Total Submissions: 341.4K
 * Testcase Example:  '"hello"'
 *
 * Write a function that takes a string as input and returns the string
 * reversed.
 * 
 * 
 * Example:
 * Given s = "hello", return "olleh".
 * 
 */
public class Solution {
    public String reverseString(String s) {
        int len = s.length();
        char[] ss = s.toCharArray();
        for(int i=0;i<len/2;i++)
        {
            char t = ss[i];
            ss[i] = ss[len-1-i];
            ss[len-1-i] = t;
        }
        String a = new String(ss);
        return a;
    }
}
