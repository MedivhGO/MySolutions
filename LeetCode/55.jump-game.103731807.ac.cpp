/*
 * [55] Jump Game
 *
 * https://leetcode.com/problems/jump-game/description/
 *
 * algorithms
 * Medium (29.58%)
 * Total Accepted:    147.4K
 * Total Submissions: 498.4K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * 
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 * 
 * 
 * Each element in the array represents your maximum jump length at that
 * position. 
 * 
 * 
 * Determine if you are able to reach the last index.
 * 
 * 
 * 
 * For example:
 * A = [2,3,1,1,4], return true.
 * 
 * 
 * A = [3,2,1,0,4], return false.
 * 
 */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> f(nums.size(),0);
        f[0] = 0;
        for (int i=1;i<nums.size();i++) {
            f[i] = max(f[i-1],nums[i-1])-1;
            if (f[i] < 0) return false;
        }
        
        return f[nums.size()-1] >=0;
    }
};
