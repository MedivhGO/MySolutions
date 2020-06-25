/*
 * [268] Missing Number
 *
 * https://leetcode.com/problems/missing-number/description/
 *
 * algorithms
 * Easy (44.51%)
 * Total Accepted:    149K
 * Total Submissions: 334.8K
 * Testcase Example:  '[3,0,1]'
 *
 * 
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
 * find the one that is missing from the array.
 * 
 * 
 * Example 1
 * 
 * Input: [3,0,1]
 * Output: 2
 * 
 * 
 * 
 * Example 2
 * 
 * Input: [9,6,4,2,3,5,7,0,1]
 * Output: 8
 * 
 * 
 * 
 * 
 * 
 * Note:
 * Your algorithm should run in linear runtime complexity. Could you implement
 * it using only constant extra space complexity?
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ret = 0;
        for (int i=0;i<nums.size();++i) {
            ret ^= i;
            ret ^= nums[i];
        }
        return ret^nums.size();
        
    }
};
