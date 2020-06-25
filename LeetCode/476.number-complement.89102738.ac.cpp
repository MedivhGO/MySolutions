/*
 * [476] Number Complement
 *
 * https://leetcode.com/problems/number-complement/description/
 *
 * algorithms
 * Easy (60.96%)
 * Total Accepted:    65.7K
 * Total Submissions: 107.8K
 * Testcase Example:  '5'
 *
 * Given a positive integer, output its complement number. The complement
 * strategy is to flip the bits of its binary representation.
 * 
 * Note:
 * 
 * The given integer is guaranteed to fit within the range of a 32-bit signed
 * integer.
 * You could assume no leading zero bit in the integer’s binary
 * representation.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: 5
 * Output: 2
 * Explanation: The binary representation of 5 is 101 (no leading zero bits),
 * and its complement is 010. So you need to output 2.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 1
 * Output: 0
 * Explanation: The binary representation of 1 is 1 (no leading zero bits), and
 * its complement is 0. So you need to output 0.
 * 
 * 
 */
class Solution {
public:
    int findComplement(int num) {
      vector<int> ivec;
      while(num) {
          int t = num%2;
          if(t==0)
            ivec.push_back(1);
          else
            ivec.push_back(0);
          num = num / 2;
      }
      int res=0;
      for(int i =0 ;i< ivec.size();i++) {
          res+=ivec[i]*pow(2,i);
      }
      return res;
    }
};
