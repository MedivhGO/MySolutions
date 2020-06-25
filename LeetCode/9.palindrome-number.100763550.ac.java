/*
 * [9] Palindrome Number
 *
 * https://leetcode.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (35.64%)
 * Total Accepted:    282.4K
 * Total Submissions: 792.5K
 * Testcase Example:  '-2147483648'
 *
 * Determine whether an integer is a palindrome. Do this without extra space.
 * 
 * click to show spoilers.
 * 
 * Some hints:
 * 
 * Could negative integers be palindromes? (ie, -1)
 * 
 * If you are thinking of converting the integer to string, note the
 * restriction of using extra space.
 * 
 * You could also try reversing an integer. However, if you have solved the
 * problem "Reverse Integer", you know that the reversed integer might
 * overflow. How would you handle such case?
 * 
 * There is a more generic way of solving this problem.
 * 
 * 
 */
import java.math.BigDecimal;
public class Solution {
    public boolean isPalindrome(int x) {
        BigDecimal bg = new BigDecimal(x);
        String s = bg.toString();
        StringBuffer sb = new StringBuffer(s);
        StringBuffer sb2 = sb.reverse();
        String s2 = sb2.toString();
        if (s.equals(s2))
            return true;
        else
            return false;
    }
}
