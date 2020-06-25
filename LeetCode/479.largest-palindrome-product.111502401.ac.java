/*
 * [479] Largest Palindrome Product
 *
 * https://leetcode.com/problems/largest-palindrome-product/description/
 *
 * algorithms
 * Easy (24.80%)
 * Total Accepted:    7.8K
 * Total Submissions: 31.4K
 * Testcase Example:  '1'
 *
 * Find the largest palindrome made from the product of two n-digit numbers.
 * ⁠Since the result could be very large, you should return the largest
 * palindrome mod 1337.
 * 
 * Example:
 * Input: 2
 * Output: 987
 * Explanation: 99 x 91 = 9009, 9009 % 1337 = 987
 * 
 * 
 * 
 * 
 * Note:
 * The range of n is [1,8].
 * 
 * 
 */
public class Solution {
    public int largestPalindrome(int n) {
        if(n == 1) return 9;
        int m = 1337;
        int mod = (int)Math.pow(10, n);
        int max = (int)Math.pow(10, n)-1;
        long pro = (long)max*(long)max;
        int right = (int)(pro%mod);
        int left = (int)(pro/mod);
        if(left == reverse(right,n)) return (int)(pro%m);
        if(left > right) {left--;}
        pro = (long)left*(long)mod+(long)reverse(left,n);
        while(left != mod/10){
            for(int i = max;i>pro/i;i--){
                if(pro%i == 0 ) {
                    return (int)(pro%m);
                }
            }
            left--;
            pro = (long)left*(long)mod+(long)reverse(left,n);
        }
        
        return (int)(pro%m);
    }
    
    private int reverse(int n, int dig){
        int x = n;
        int res = 0;
        int ten = (int)Math.pow(10,dig-1);
        while(x != 0 ){
            int d = x%10;
            res+=ten*d;
            ten/=10;
            x/=10;
        }
        return res;
    }
   
}
