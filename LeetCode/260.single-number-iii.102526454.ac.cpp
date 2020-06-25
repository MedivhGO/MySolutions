/*
 * [260] Single Number III
 *
 * https://leetcode.com/problems/single-number-iii/description/
 *
 * algorithms
 * Medium (52.59%)
 * Total Accepted:    76.4K
 * Total Submissions: 145.2K
 * Testcase Example:  '[1,2,1,3,2,5]'
 *
 * 
 * Given an array of numbers nums, in which exactly two elements appear only
 * once and all the other elements appear exactly twice. Find the two elements
 * that appear only once.
 * 
 * 
 * For example:
 * 
 * 
 * Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
 * 
 * 
 * Note:
 * 
 * The order of the result is not important. So in the above example, [5, 3] is
 * also correct.
 * Your algorithm should run in linear runtime complexity. Could you implement
 * it using only constant space complexity?
 * 
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        
        vector<int> ans(2,0);
        int r=0;
        
        for (int i=0;i<nums.size();i++) {
            r^=nums[i];
        }
        
        int last = r & (~(r-1));
        
        for (int i=0;i<nums.size();i++) {
            if ((last & nums[i]) != 0)
                ans[0]^= nums[i];
            else 
                ans[1]^=nums[i];
        }
        
        return ans;
    }
};
