/*
 * [172] Factorial Trailing Zeroes
 *
 * https://leetcode.com/problems/factorial-trailing-zeroes/description/
 *
 * algorithms
 * Easy (36.62%)
 * Total Accepted:    107.2K
 * Total Submissions: 292.7K
 * Testcase Example:  '0'
 *
 * Given an integer n, return the number of trailing zeroes in n!.
 * 
 * Note: Your solution should be in logarithmic time complexity.
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test
 * cases.
 */
class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while(n) {
            res+=n/5;
            n=n/5;
        }
        return res;
    }
};
