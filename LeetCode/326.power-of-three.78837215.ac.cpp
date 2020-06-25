/*
 * [326] Power of Three
 *
 * https://leetcode.com/problems/power-of-three/description/
 *
 * algorithms
 * Easy (40.53%)
 * Total Accepted:    112.7K
 * Total Submissions: 278K
 * Testcase Example:  '27'
 *
 * 
 * ⁠   Given an integer, write a function to determine if it is a power of
 * three.
 * 
 * 
 * ⁠   Follow up:
 * ⁠   Could you do it without using any loop / recursion?
 * 
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==0)
            return false;
        if(n==1)
            return true;
            
        while(n%3==0)
        {
            n = n/3;
        }
        if(n==1)
            return true;
        else 
            return false;
    }
};
