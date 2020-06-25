/*
 * [342] Power of Four
 *
 * https://leetcode.com/problems/power-of-four/description/
 *
 * algorithms
 * Easy (38.85%)
 * Total Accepted:    77.5K
 * Total Submissions: 199.6K
 * Testcase Example:  '16'
 *
 * 
 * Given an integer (signed 32 bits), write a function to check whether it is a
 * power of 4.
 * 
 * Example:
 * Given num = 16, return true.
 * Given num = 5, return false.
 * 
 * 
 * Follow up: Could you solve it without loops/recursion?
 * 
 * Credits:Special thanks to @yukuairoy  for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
    bool isPowerOfFour(int num) {
    if(num <= 0){
        return false;
    }
    
    bitset<32> n(num);
    if(n.count() != 1){ //确定所有位中只有1个1.
        return false;
    }
    for(int i = 0; i < 32; i++){
        if(n[i] == 1 && i % 2 == 0){ //偶数下标的位置为1
            return true;
        }
    }
    return false;
}
};
