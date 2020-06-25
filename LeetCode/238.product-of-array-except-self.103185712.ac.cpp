/*
 * [238] Product of Array Except Self
 *
 * https://leetcode.com/problems/product-of-array-except-self/description/
 *
 * algorithms
 * Medium (50.04%)
 * Total Accepted:    129.6K
 * Total Submissions: 259K
 * Testcase Example:  '[0,0]'
 *
 * 
 * Given an array of n integers where n > 1, nums, return an array output such
 * that output[i] is equal to the product of all the elements of nums except
 * nums[i].
 * 
 * Solve it without division and in O(n).
 * 
 * For example, given [1,2,3,4], return [24,12,8,6].
 * 
 * Follow up:
 * Could you solve it with constant space complexity? (Note: The output array
 * does not count as extra space for the purpose of space complexity analysis.)
 */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int n = nums.size();
        int fromBegin = 1;
        int fromLast = 1;
        
        vector<int> ans(n,1);
        
        for (int i=0;i<n;i++) {
            ans[i] *= fromBegin;
            fromBegin*= nums[i];
            ans[n-1-i]  *= fromLast;
            fromLast *= nums[n-1-i];
        }
        
        return ans;
    }
};
