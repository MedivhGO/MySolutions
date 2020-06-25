/*
 * [69] Sqrt(x)
 *
 * https://leetcode.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (28.46%)
 * Total Accepted:    199.2K
 * Total Submissions: 700K
 * Testcase Example:  '4'
 *
 * Implement int sqrt(int x).
 * 
 * Compute and return the square root of x.
 * 
 * x is guaranteed to be a non-negative integer.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: 4
 * Output: 2
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since we want to return
 * an integer, the decimal part will be truncated.
 * 
 * 
 */
class Solution {
public:
    int mySqrt(int x) {
       if (x < 2)
            return x;
        
        int sres = sqrt(x);
        int y = x/2;
        while  (abs(sres-y)>0.00001){
         
            y = (1.0*y+1.0*x/y)*0.5;
            cout << y << endl;
        }
        int res = floor(y);
        return  res;
    }
};
