/*
 * [561] Array Partition I
 *
 * https://leetcode.com/problems/array-partition-i/description/
 *
 * algorithms
 * Easy (66.48%)
 * Total Accepted:    59.5K
 * Total Submissions: 89.5K
 * Testcase Example:  '[1,4,3,2]'
 *
 * 
 * Given an array of 2n integers, your task is to group these integers into n
 * pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of
 * min(ai, bi) for all i from 1 to n as large as possible.
 * 
 * 
 * Example 1:
 * 
 * Input: [1,4,3,2]
 * 
 * Output: 4
 * Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3,
 * 4).
 * 
 * 
 * 
 * Note:
 * 
 * n is a positive integer, which is in the range of [1, 10000].
 * All the integers in the array will be in the range of [-10000, 10000].
 * 
 * 
 */
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        
        const int len = nums.size();
        
        if (len == 0)
            return 0;
        sort(nums.begin(),nums.end());
        int ans = 0;
        if (len == 2)
            return nums[0];
            
        for (int i=0;i < nums.size();i+=2) {
            ans += nums[i];
        }
        
        return ans;
        
        
    }
};
