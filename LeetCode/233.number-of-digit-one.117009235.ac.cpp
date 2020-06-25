/*
 * [233] Number of Digit One
 *
 * https://leetcode.com/problems/number-of-digit-one/description/
 *
 * algorithms
 * Hard (28.81%)
 * Total Accepted:    32.5K
 * Total Submissions: 113K
 * Testcase Example:  '-1'
 *
 * Given an integer n, count the total number of digit 1 appearing in all
 * non-negative integers less than or equal to n.
 * 
 * 
 * For example: 
 * Given n = 13,
 * Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12,
 * 13.
 * 
 */
class Solution {
public:
    int countDigitOne(int n) {
            int count=0;
            long long i=1;
            for(i=1;i<=n;i*=10)
            {
                //i表示当前分析的是哪一个数位
                int a = n/i,b = n%i;
                count=count+(a+8)/10*i+(a%10==1)*(b+1);
            }
            return count; 
    }
};
