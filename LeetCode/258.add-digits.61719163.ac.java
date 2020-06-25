/*
 * [258] Add Digits
 *
 * https://leetcode.com/problems/add-digits/description/
 *
 * algorithms
 * Easy (51.55%)
 * Total Accepted:    183.9K
 * Total Submissions: 356.7K
 * Testcase Example:  '0'
 *
 * 
 * Given a non-negative integer num, repeatedly add all its digits until the
 * result has only one digit. 
 * 
 * 
 * 
 * For example:
 * 
 * 
 * Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only
 * one digit, return it.
 * 
 * 
 * Follow up:
 * Could you do it without any loop/recursion in O(1) runtime?
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
public class Solution {
    public int addDigits(int num) {
        if(num<10)
            return num;
        int sum =0;
        while(num!=0)
        {
            sum += num%10;
            num = num/10;
        }
        if(sum < 10)
            return sum;
        else
            return addDigits(sum);
        
        
    }
}
