/*
 * [136] Single Number
 *
 * https://leetcode.com/problems/single-number/description/
 *
 * algorithms
 * Easy (55.08%)
 * Total Accepted:    262.2K
 * Total Submissions: 476K
 * Testcase Example:  '[1]'
 *
 * Given an array of integers, every element appears twice except for one. Find
 * that single one.
 * 
 * 
 * Note:
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 * 
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        if (nums.empty()) return ans;
        for (auto x : nums) {
            ans^= x;
        }
        return ans;
    }
};
