/*
 * [303] Range Sum Query - Immutable
 *
 * https://leetcode.com/problems/range-sum-query-immutable/description/
 *
 * algorithms
 * Easy (31.26%)
 * Total Accepted:    85.6K
 * Total Submissions: 273.8K
 * Testcase Example:  '["NumArray","sumRange","sumRange","sumRange"]\n[[[-2,0,3,-5,2,-1]],[0,2],[2,5],[0,5]]'
 *
 * Given an integer array nums, find the sum of the elements between indices i
 * and j (i ≤ j), inclusive.
 * 
 * Example:
 * 
 * Given nums = [-2, 0, 3, -5, 2, -1]
 * 
 * sumRange(0, 2) -> 1
 * sumRange(2, 5) -> -1
 * sumRange(0, 5) -> -3
 * 
 * 
 * 
 * Note:
 * 
 * You may assume that the array does not change.
 * There are many calls to sumRange function.
 * 
 * 
 */
class NumArray {
public:
    vector<int>  dp;
    NumArray(vector<int> nums) {
        const int len  = nums.size();
        dp.push_back(0);
        for (int i= 0;i<len;i++)
            dp.push_back(dp[i]+nums[i]);
       
    }
    int sumRange(int i, int j) {
      return dp[j+1]-dp[i];
    }
};
