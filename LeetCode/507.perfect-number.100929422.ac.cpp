/*
 * [507] Perfect Number
 *
 * https://leetcode.com/problems/perfect-number/description/
 *
 * algorithms
 * Easy (33.13%)
 * Total Accepted:    18.7K
 * Total Submissions: 56.3K
 * Testcase Example:  '28'
 *
 * We define the Perfect Number is a positive integer that is equal to the sum
 * of all its positive divisors except itself. 
 * 
 * Now, given an integer n, write a function that returns true when it is a
 * perfect number and false when it is not.
 * 
 * 
 * Example:
 * 
 * Input: 28
 * Output: True
 * Explanation: 28 = 1 + 2 + 4 + 7 + 14
 * 
 * 
 * 
 * Note:
 * The input number n will not exceed 100,000,000. (1e8)
 * 
 */
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 1)
            return false;
        int sum = 1;
        for (int i=2;i<sqrt(num);i++) {
            if(num%i == 0) {
                sum+=i;
                sum+=num/i;
            }
        }
        if (num == sum)
            return true;
        else 
            return false;
        
    }
};
