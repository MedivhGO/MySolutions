/*
 * [402] Remove K Digits
 *
 * https://leetcode.com/problems/remove-k-digits/description/
 *
 * algorithms
 * Medium (26.12%)
 * Total Accepted:    26.9K
 * Total Submissions: 102.8K
 * Testcase Example:  '"1432219"\n3'
 *
 * Given a non-negative integer num represented as a string, remove k digits
 * from the number so that the new number is the smallest possible.
 * 
 * 
 * Note:
 * 
 * The length of num is less than 10002 and will be ≥ k.
 * The given num does not contain any leading zero.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: num = "1432219", k = 3
 * Output: "1219"
 * Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219
 * which is the smallest.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: num = "10200", k = 1
 * Output: "200"
 * Explanation: Remove the leading 1 and the number is 200. Note that the
 * output must not contain leading zeroes.
 * 
 * 
 * 
 * Example 3:
 * 
 * Input: num = "10", k = 2
 * Output: "0"
 * Explanation: Remove all the digits from the number and it is left with
 * nothing which is 0.
 * 
 * 
 */
class Solution {
public:
    string removeKdigits(string num, int k) {
         while (k > 0) {
            int n = num.size();
            int i = 0;
            while (i+1<n && num[i]<=num[i+1])  i++;// 寻找peak
            num.erase(i, 1);
            k--;
        }
        // trim leading zeros
        int s = 0;
        while (s<(int)num.size()-1 && num[s]=='0')  s++;
        num.erase(0, s); //删除从0开始后面的的s个‘0’；
        
        return num=="" ? "0" : num;
    }
};
