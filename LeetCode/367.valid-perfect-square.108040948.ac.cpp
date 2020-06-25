/*
 * [367] Valid Perfect Square
 *
 * https://leetcode.com/problems/valid-perfect-square/description/
 *
 * algorithms
 * Easy (38.53%)
 * Total Accepted:    61.8K
 * Total Submissions: 160.4K
 * Testcase Example:  '16'
 *
 * Given a positive integer num, write a function which returns True if num is
 * a perfect square else False.
 * 
 * 
 * Note: Do not use any built-in library function such as sqrt.
 * 
 * 
 * Example 1:
 * 
 * Input: 16
 * Returns: True
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 14
 * Returns: False
 * 
 * 
 * 
 * Credits:Special thanks to @elmirap for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
     int mySqrt(int x) {
        int left = 1,right = x; //所有1到最大的整数
        
        
        if(x<2) return x;
        
        while(left <= right) {
            const int mid = left + (right-left) / 2;
            if(x/mid > mid) { //不要使用x > mid * mid，会溢出
                left = mid + 1;
               
            } else if(x / mid < mid) {
                right = mid - 1;
            } else {
                return mid;
            }
        }
        return 0; //没找到该数的平方根，就返回0
    }
    bool isPerfectSquare(int num) {
        int c = mySqrt(num);
        if(c*c == num)
            return true;
        else
            return false;
    }
};
