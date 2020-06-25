/*
 * [29] Divide Two Integers
 *
 * https://leetcode.com/problems/divide-two-integers/description/
 *
 * algorithms
 * Medium (15.86%)
 * Total Accepted:    120.6K
 * Total Submissions: 760.8K
 * Testcase Example:  '0\n1'
 *
 * 
 * Divide two integers without using multiplication, division and mod
 * operator.
 * 
 * 
 * If it is overflow, return MAX_INT.
 * 
 */
class Solution {
public:
    int divide(int dividend, int divisor) {
        long long a = dividend >= 0 ? dividend:-(long long) dividend;
        long long b =  divisor >= 0 ? divisor : -(long long) divisor;
        long long result = 0;
        while (a>=b) {
            long long c = b;
            for (int i = 0; a >= c;i++,c <<= 1) {
                a -= c;
                result+= 1<<i;
            }
        }
        
        result =  ((dividend^divisor)>>31) ? (-result) : (result); //判断最后结果的符号 
        if (result > INT_MAX) return INT_MAX;
        if (result < INT_MIN) return INT_MAX;
        return result;
    }
};
