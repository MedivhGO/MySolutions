/*
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (31.46%)
 * Total Accepted:    156.6K
 * Total Submissions: 497.9K
 * Testcase Example:  '[0,0,0]\n1'
 *
 * Given an array S of n integers, find three integers in S such that the sum
 * is closest to a given number, target. Return the sum of the three integers.
 * You may assume that each input would have exactly one solution.
 * 
 * 
 * ⁠   For example, given array S = {-1 2 1 -4}, and target = 1.
 * 
 * ⁠   The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 */
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
         int result = 0;
         int min_gap = INT_MAX;
         
         sort(nums.begin(),nums.end());
         
         for (auto a = nums.begin(); a < prev(nums.end(),2);++a) {
             auto b = next(a);
             auto c = prev(nums.end());
             
             while (b < c) {
                 const int sum = *a+*b+*c;
                 const int gap = abs(sum-target);
                 
                 if (gap < min_gap) {
                     min_gap = gap;
                     result = sum;
                 }
                 if (sum < target) b++;
                 else --c;
             }
         }
         return result;
    }
};
