/*
 * [50] Pow(x, n)
 *
 * https://leetcode.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (26.00%)
 * Total Accepted:    188.8K
 * Total Submissions: 726.3K
 * Testcase Example:  '2.00000\n10'
 *
 * Implement pow(x, n).
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: 2.00000, 10
 * Output: 1024.00000
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 2.10000, 3
 * Output: 9.26100
 * 
 * 
 */
class Solution {
public:
    double myPow(double x, int n) {
        if(n>=0)
            return power(x,n);
        else
            return 1.0/power(x,-n);
    }
private:
    double power(double x,int n) {
        if(n==0) return 1;
        double v = power(x,n/2);
        if(n%2 == 0)
            return v * v;
        else 
            return v*v*x;
        
    }
};
