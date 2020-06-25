/*
 * [633] Sum of Square Numbers
 *
 * https://leetcode.com/problems/sum-of-square-numbers/description/
 *
 * algorithms
 * Easy (32.25%)
 * Total Accepted:    17.6K
 * Total Submissions: 54.6K
 * Testcase Example:  '5'
 *
 * 
 * Given a non-negative integer c, your task is to decide whether there're two
 * integers a and b such that a2 + b2 = c.
 * 
 * 
 * Example 1:
 * 
 * Input: 5
 * Output: True
 * Explanation: 1 * 1 + 2 * 2 = 5
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 3
 * Output: False
 * 
 * 
 * 
 */
class Solution {
public:
    bool judgeSquareSum(int c) {
        if (c == 0)
            return true;
        unordered_set<int> se;
        for (int i=0;i<=sqrt(c);++i) {
            se.insert(i*i);
        }
        
        for (int i=0;i<=sqrt(c);++i) {
            if (se.find(c-(i*i))!=se.end())
                return true;
        }
        return false;
    }
};
