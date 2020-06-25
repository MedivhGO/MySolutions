/*
 * [190] Reverse Bits
 *
 * https://leetcode.com/problems/reverse-bits/description/
 *
 * algorithms
 * Easy (29.46%)
 * Total Accepted:    121.6K
 * Total Submissions: 412.7K
 * Testcase Example:  '           0 (00000000000000000000000000000000)'
 *
 * Reverse bits of a given 32 bits unsigned integer.
 * 
 * For example, given input 43261596 (represented in binary as
 * 00000010100101000001111010011100), return 964176192 (represented in binary
 * as 00111001011110000010100101000000).
 * 
 * 
 * Follow up:
 * If this function is called many times, how would you optimize it?
 * 
 * 
 * Related problem: Reverse Integer
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test
 * cases.
 */
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        unsigned int mask = 1,ret = 0;
        for (int i=0; i < 32; ++i) {
            ret <<= 1;
            if(mask & n) ret |= 1;
            mask <<= 1;
        }
        return ret;
    }
};
