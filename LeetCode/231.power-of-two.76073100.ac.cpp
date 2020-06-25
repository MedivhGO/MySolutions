/*
 * [231] Power of Two
 *
 * https://leetcode.com/problems/power-of-two/description/
 *
 * algorithms
 * Easy (40.50%)
 * Total Accepted:    157.6K
 * Total Submissions: 389.3K
 * Testcase Example:  '1'
 *
 * 
 * Given an integer, write a function to determine if it is a power of two.
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1)
            return true;
        else{
            bitset<1000> b(n);
            if(b.count()==1)
                return true;
            else
                return false;
        }
        
        
    }
};
