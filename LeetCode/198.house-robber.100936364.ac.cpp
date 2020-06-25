/*
 * [198] House Robber
 *
 * https://leetcode.com/problems/house-robber/description/
 *
 * algorithms
 * Easy (39.61%)
 * Total Accepted:    173.5K
 * Total Submissions: 438K
 * Testcase Example:  '[]'
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed, the only constraint stopping
 * you from robbing each of them is that adjacent houses have security system
 * connected and it will automatically contact the police if two adjacent
 * houses were broken into on the same night.
 * 
 * Given a list of non-negative integers representing the amount of money of
 * each house, determine the maximum amount of money you can rob tonight
 * without alerting the police.
 * 
 * Credits:Special thanks to @ifanchu for adding this problem and creating all
 * test cases. Also thanks to @ts for adding additional test cases.
 */
class Solution {
public:
    int mem[100];
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        const int len = nums.size();
        mem[len-1] = nums[len-1];
        mem[len-2] = max(nums[len-1],nums[len-2]);
        for (int i=len-3;i>=0;i--) {
            mem[i] = max(nums[i]+mem[i+2],mem[i+1]);
        }
        return mem[0];
    }
};
